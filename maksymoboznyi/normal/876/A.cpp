#include <bits/stdc++.h>
#define int long long
#define small -2000000000000000000
#define big 2000000000000000000
#define pb push_back
using namespace std;
int n, a, b, c, now = 1;
signed main()
{
    int ans = 0;
    cin >> n >> a >> b >> c;
    for (int i = 1; i <n; i++)
    {
        if (now == 1)
            if (a > b)
            {
                now = 3;
                ans += b;
            }
            else
            {
                now = 2;
                ans += a;
            }
        else
            if (now == 2)
                if (a > c)
                {
                    ans += c;
                    now = 3;
                }
                else
                {
                    ans += a;
                    now = 1;
                }
            else
                if (b > c)
                {
                    now = 2;
                    ans += c;
                }
                else
                {
                    now = 1;
                    ans += b;
                }
    }
    cout << ans;
    return 0;
}