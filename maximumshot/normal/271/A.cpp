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

using namespace std;

bool r(LL x)
{
    int cnt[10] = {0};
    while(x) {cnt[x % 10]++, x/= 10;}
    for(int i(0);i < 10;i++) if(cnt[i] > 1) return false;
    return true;
}

bool solve()
{
    LL y;

    cin >> y;

    for(int i(y + 1);;i++)
    {
        if(r(i)) 
        {
            cout << i << '\n';
            return true;
        }
    }

    return true;
}

int main()
{
    //while(solve()) {}
    solve();

    return 0;
}