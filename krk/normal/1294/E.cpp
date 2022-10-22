#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, m;
vector <vector <int> > B;
int sav[Maxn];
ll res;

int main()
{
    scanf("%d %d", &n, &m);
    B.resize(n);
    for (int i = 0; i < n; i++) {
        B[i].resize(m);
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
            B[i][j] -= (j + 1);
            if (B[i][j] % m == 0)
                B[i][j] /= m;
            else B[i][j] = -1;
            if (B[i][j] < 0 || B[i][j] >= n) B[i][j] = -1;
        }
    }
    for (int j = 0; j < m; j++) {
        fill(sav, sav + n, 0);
        for (int i = 0; i < n; i++)
            if (B[i][j] != -1) sav[(i - B[i][j] + n) % n]++;
        int mx = sav[0];
        for (int i = 1; i < n; i++)
            mx = max(mx, sav[i] - i);
        res += n - mx;
    }
    printf("%I64d\n", res);
    return 0;
}