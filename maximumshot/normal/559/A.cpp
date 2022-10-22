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

LL get(int a) {
    LL ans = 0, d = 1;
    for(LL i(1);i <= a;i++, d += 2) {
        ans += d;
    }
    return ans;
}

bool solve()
{      
    int a, b, c, d, e, f;

    cin >> a >> b >> c >> d >> e >> f;

    LL ans = get(d + e + f) - get(d) - get(b) - get(f);

    cout << ans << '\n';

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}