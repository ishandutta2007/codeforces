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

LL c, hr, hb, wr, wb;

LL get(LL x)  // x   
{
    LL y = (c - x * wr) / wb;
    return (x * hr + y * hb);
}

LL get2(LL y)
{
	LL x = (c - y * wb) / wr;
	return (x * hr + y * hb);
}

bool solve()
{

    cin >> c >> hr >> hb >> wr >> wb;

	LL ans = max((c / wr) * hr, (c / wb) * hb);

	for(LL x(0);x <= min(10000000ll, (c / wr));x++)
		ans = max(ans, get(x)), ans = max(ans, get((c / wr) - x));
	for(LL y(0);y <= min(10000000ll, (c / wb));y++)
		ans = max(ans, get2(y)), ans = max(ans, get2((c / wb) - y));

	cout << ans << '\n';
	return true;

    /*LL l = 0, r = c / wr, m1, m2;

    while(r - l > 1)
    {
        m1 = l + (r - l) / 3;
        m2 = r - (r - l) / 3;
        LL v1, v2;
        v1 = get(m1);
        v2 = get(m2);
        if(v1 < v2) l = m1;
        else r = m2;
    }

    LL ans = -inf64;

    for(LL i(-10);i <= 10;i++)
    {
        LL x = l + i;
        if(x < 0 || x > (c / wr)) continue;
        ans = max(ans, get(x));
    }

    printf("%I64d\n", ans);*/

    return true;
}   

int main() 
{
    //while(solve());
    solve();

    return 0;
}