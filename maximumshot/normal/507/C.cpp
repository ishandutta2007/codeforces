#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);

LL Abs(LL x) {return (x >= 0?x : -x);}
int sign(LD x) {return (x >= 0?1 : -1);}

using namespace std;

bool solve()
{
    LL h, n;

    cin >> h >> n;

    // 2 ^ i .. 2 * (i + 1) - 1

    int type = 0;
    LL ans = 0, val = 0;

    for(int i(0);i < h;i++)
    {
        // 1 .. 2 ^ (h - i)
        ans++;

        if(!type)
        {
            if(n <= (1ll << (h - i - 1)) + val) type ^= 1;
            else ans += (1ll << (h - i)) - 1, val += (1ll << (h - i - 1));
        }else
        {
            if(n <= (1ll << (h - i - 1)) + val) ans += (1ll << (h - i)) - 1;
            else type ^= 1, val += (1ll << (h - i - 1));;
        }
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