#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, m, b[N];
vector<vector<int> > a;

int main()
{
    cin >> n >> m;
    a.resize(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], a[i][j]--;
    int ans = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++)
            b[i] = 0;
        for (int i = 1; i <= n; i++)
            if (a[i][j] % m == j - 1) {
                int val = a[i][j] / m + 1;
                //cout << val << ' ' << i << endl;
                if (val > n)
                    continue;
                if (val <= i)
                    b[i - val + 1] ++;
                else
                    b[n + 1 + i - val]++;
            }
        int ans_mn = 1e9;
        for (int i = 1; i <= n; i++)
            ans_mn = min(ans_mn, (i - 1) + (n - b[i]));//, cout << b[i] << ' ';
        ans += ans_mn;
        //cout << ans << endl;
    }
    cout << ans;
    return 0;
}