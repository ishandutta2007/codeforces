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
    int n;

    scanf("%d", &n);

    vec<int> a(n);

    for(int i(0);i < n;i++)
        scanf("%d", &a[i]);

    int ans = min(a[0], a[n - 1]);
    
    for(int i(0);i < n - 1;i++) {
        ans = min(ans, max(a[i], a[i + 1]));
    }

    printf("%d\n", ans);

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}