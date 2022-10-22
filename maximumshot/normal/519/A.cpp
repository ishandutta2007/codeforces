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
    vec<LL> cnt(26);

    cnt['Q' - 'A'] = 9;
    cnt['R' - 'A'] = 5;
    cnt['B' - 'A'] = 3;
    cnt['N' - 'A'] = 3;
    cnt['P' - 'A'] = 1;
    cnt['K' - 'A'] = 0;

    LL c1, c2;
    char c;
    c1 = c2 = 0;
    
    for(int i(0);i < 8;i++)
    {
        for(int j(0);j < 8;j++)
        {
            cin >> c;
            if(c == '.') continue;
            if(c >= 'A' && c <= 'Z')
                c1 += cnt[c - 'A'];
            else
                c2 += cnt[c - 'a'];
        }
    }

    puts(c1 > c2?"White" : (c1 < c2?"Black" : "Draw"));

    return true;
}

int main()
{
    //while(solve());
    solve();
    
    return 0;
}