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
#include <iomanip>

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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    vec< int > t(n + 1);
    for(int i = 1;i <= n;i++) cin >> t[i];

    vec< int > preff(n + 2, 0), suff(n + 2, 0);

    for(int i = 1;i <= n;i++) {
        preff[i] = preff[i - 1] + (t[i] >= 0);
    }

    for(int i = n;i >= 1;i--) {
        suff[i] = suff[i + 1] + (t[i] <= 0); 
    }

    int ans = inf;

    for(int k = 1;k <= n - 1;k++) {
        ans = min(ans, preff[k] + suff[k + 1]);
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