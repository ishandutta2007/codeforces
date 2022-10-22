#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <queue>
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
    int n;
    map<LL, int> c, p;
    LL x;

    cin >> n;

    for(int i(0);i < n;i++)
    {
        cin >> x;
        c[x]++;
        p[x]++;
    }

    for(int i(0);i < n - 1;i++)
    {
        cin >> x;
        c[x]--;
    }

    LL ans = -1;
    
    for(map<LL, int>::iterator i = c.begin();i != c.end();i++)
    {
        if(i->second == 0) continue;
        ans = i->first;
        break;
    }

    p[ans]--;

    cout << ans << '\n';

    for(int i(0);i < n - 2;i++)
    {
        cin >> x;
        p[x]--;
    }

    for(map<LL, int>::iterator i = p.begin();i != p.end();i++)
    {
        if(i->second == 0) continue;
        ans = i->first;
        break;
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