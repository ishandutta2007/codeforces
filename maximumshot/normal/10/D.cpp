// by maximumSHOT
#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string>
#include <fstream>
#include <stdio.h>
 
using namespace std;
 
#define ALL(x) (x).begin(), (x).end()
#define vec vector
#define mp make_pair
#define close() puts("Ok!\n"); return true;
 
typedef long long LL;
typedef long double LD;
 
const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
 
LL Abs(LL x) {return (x >= 0?x : -x);}

bool solve()
{
    int n, m;

    cin >> n;

    vec<int> a(n + 1);

    for(int i(1);i <= n;i++) cin >> a[i];

    cin >> m;

    vec<int> b(m + 1);

    for(int i(1);i <= m;i++) cin >> b[i];

    vec<int> dp(n + 1), from(n + 1, -1), q(n + 1, -1);

    int pos = -1;

    for(int i(1);i <= m;i++) if(b[i] == a[1]) {pos = i; break;}

    if(pos != -1)
    {
        dp[1] = 1;
        q[1] = pos;
    }

    for(int i(2);i <= n;i++)
    {
        for(int j(1);j < i;j++)
        {
            // (... j) -> i

            if(dp[j] && a[i] > a[j])
            {
                pos = -1;
                for(int z(q[j] + 1);z <= m;z++) if(b[z] == a[i]) {pos = z; break;}
                
                if(pos != -1)
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        from[i] = j;
                        q[i] = pos;
                    }
                }
            }else
            {
                pos = -1;

                for(int z(1);z <= m;z++) if(b[z] == a[i]) {pos = z; break;}

                if(pos != -1 && dp[i] == 0)
                {
                    dp[i] = 1;
                    q[i] = pos;
                }
            }
        }
    }
    
    int ans = -1;

    for(int i(1);i <= n;i++) if(ans == -1 || dp[ans] < dp[i]) ans = i;

    cout << dp[ans] << '\n';

    if(dp[ans] == 0) return true;

    vec<int> way;

    for(int v = ans;v != -1;v = from[v]) way.push_back(v);

    reverse(ALL(way));

    for(int i(0);i < (int)way.size();i++) cout << a[way[i]] << ' ';

    return true;
}
 
int main()
{
    //while(solve());
    solve();
 
    return 0;
}