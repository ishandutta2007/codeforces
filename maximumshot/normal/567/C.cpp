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
#include <time.h>

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
const LL MOD = inf + 7;
const double pi = acos(-1.0);

using namespace std;

bool solve()
{
    int n;
    LL k;

    cin >> n >> k;

    vec< LL > a(n);
    for(int i = 0;i < n;i++) cin >> a[i];

    map< LL, int > l, r;

    for(int i = 0;i < n;i++) {
        r[a[i]]++;
    }

    LL ans = 0;

    for(int i = 0;i < n;i++) {
        r[a[i]]--;
        if(a[i] % k) {
            l[a[i]]++;
            continue;
        }
        LL b1 = a[i] / k;
        LL d1, d2;
        d1 = l[b1];
        d2 = r[b1 * k * k];
        ans += d1 * d2;
        l[a[i]]++;
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