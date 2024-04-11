#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
using namespace std;


int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --) 
    {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        ll sums = 0, sum = 0;
        rep(i, 1, n)
        {
            cin >> a[i];
            sums += a[i] * a[i];
            sum += a[i];
        }
        rep(i, 1, n)
        {
            cin >> b[i];
            sums += b[i] * b[i];
            sum += b[i];
        }
        vector<vector<int>> f(n + 1, vector<int>(sum + 1));
        f[0][0] = 1;
        rep(i, 1, n)
            rep(j, min(a[i], b[i]), sum)
            {
                if (j >= a[i]) f[i][j] |= f[i - 1][j - a[i]];
                if (j >= b[i]) f[i][j] |= f[i - 1][j - b[i]];
            }
        ll ans = (n - 1) * sums;
        ll bans;
        rrep(i, sum / 2, 0)
            if (f[n][i]) 
            {
                bans = i;
                break;
            }
        cout << ans + bans * bans + (sum - bans) * (sum - bans) - sums << '\n'; 
    }
}