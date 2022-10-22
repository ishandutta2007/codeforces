#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector
#define deb(x) cerr << #x << " = " << x << '\n';

typedef unsigned long long ull;
typedef long double LD;
typedef long long LL;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;
const LL MOD = inf + 9;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int n, q;

    scanf("%d %d", &n, &q);

    vec<LL> a(2 * n + 1);

    for(int i(1);i <= n;i++)
        scanf("%I64d", &a[i]), 
        a[i + n] = a[i];

    vec<int> from(2 * n + 1), dp(2 * n + 1), last(2 * n + 1), used(2 * n + 1);
    vec<LL> sum(2 * n + 1, 0);

    for(int i(1);i <= 2 * n;i++)
        sum[i] = sum[i - 1] + a[i];

    for(int i(0);i < q;i++)
    {
        LL b;
        scanf("%I64d", &b);
        
        int j = -1;
        for(int z(1);z <= n;z++) {
            from[z] = dp[z] = used[z] = last[z] = 0;
            if(sum[z] > b) {
                if(j == -1) j = 1;
                while(sum[z] - sum[j - 1] > b) j++;
                from[z] = j - 1;
            }
            dp[z] = dp[from[z]] + 1;
            if(from[z]) {
                last[z] = last[from[z]];
            }else 
                last[z] = z;
        }
        
        int ans = n + 1;
        LL S = 0;
        for(int z(n);z >= 1;z--) {
            if(S > b) break;
            int tmp = dp[z];
            if(sum[last[z]] + S > b) tmp++; 
            ans = min(ans, tmp);
            S += a[z];
        }

        printf("%d\n", ans);
    }

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}