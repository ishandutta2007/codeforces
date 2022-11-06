#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 5e5 + 5, K = 20;
const long long M = 1e9 + 7;

int up[N][K], n, l[N], r[N], m;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < K; j++)
            up[i][j] = -1;
    for (int i = 1; i <= n; i++)
        cin >> l[i] >> r[i], up[l[i]][0] = max(r[i], up[l[i]][0]);
    for (int i = 1; i < N; i++)
        up[i][0] = max(up[i][0], up[i - 1][0]);
    for (int i = 0; i < N; i++)
        if (up[i][0] <= i)
            up[i][0] = -1;
    for (int j = 1; j < K; j++) {
        for (int i = 0; i < N; i++)
            if (up[i][j - 1] != -1)
                up[i][j] = up[up[i][j - 1]][j - 1];
        for (int i = 1; i < N; i++) {
            up[i][j] = max(up[i][j], up[i - 1][j]);
            if (up[i][j] <= i || up[i][j] == up[i][j - 1])
                up[i][j] = -1;
        }
    }
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        int ans = 0;
        int kans = 1000000;
        for (int j = K - 1; j >= 0; j--)
            if (up[x][j] != -1 && up[x][j] < y)
                x = up[x][j], ans += (1 << j);
            else
                if (up[x][j] >= y)
                    kans = min(kans, ans + (1 << j));
        if (up[x][0] >= y)
            kans = min(kans, ans + 1);
        if (kans == 1000000)
            kans = -1;
        cout << kans << "\n";
    }
    return 0;
}
/*
8 1
6 10
6 9
9 10
1 3
5 8
1 5
6 8
6 9

8 10
1 ---> 2
*/