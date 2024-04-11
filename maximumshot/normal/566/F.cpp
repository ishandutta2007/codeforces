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
#include <list>
#include <cstring>

//#include <conio.h>

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
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int n;
    scanf("%d", &n);
    
    vec< int > a(n);
    for(int i = 0;i < n;i++) scanf("%d", &a[i]);
    
    vec< int > dp(1e6 + 10), c(1e6 + 10);

    for(int i = 0;i < n;i++) {
        c[a[i]]++;
    }

    for(int i = 1e6;i >= 1;i--) {
        if(!c[i]) continue;
        for(int j = i;j <= 1e6;j += i) {
            if(!c[j]) continue;
            dp[i] = max(dp[i], dp[j] + c[i]);
        }
    }

    int ans = 1;
    for(int i = 1;i <= 1e6;i++) {
        if(!c[i]) continue;
        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}