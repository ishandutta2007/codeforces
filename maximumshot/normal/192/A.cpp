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
    LL n;

    scanf("%I64d", &n);

    for(LL x(1);;x++) {
        if(x * (x + 1) / 2 >= n) break;
        LL val = n - x * (x + 1) / 2;

        LL l, r, mid;
        l = 0, r = val;

        while(r - l > 1) {
            mid = (l + r) >> 1;
            LL tmp = mid * (mid + 1) / 2;
            if(tmp < val) l = mid + 1;
            else r = mid;
        }

        if(l * (l + 1) / 2 == val || r * (r + 1) / 2 == val) {
            puts("YES");
            return true;
        }
    }

    puts("NO");

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}