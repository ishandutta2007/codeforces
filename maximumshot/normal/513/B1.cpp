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
    int n, m, q;
    LL mx = 0;

    cin >> n >> m;

    vec<int> a(n);

    for(int i(0);i < n;i++) a[i] = i + 1;   

    do{
        LL tmp = 0, mn;

        for(int i(0);i < n;i++)
        {
            mn = inf64;
            for(int j(i);j < n;j++)
            {
                mn = min(mn, (LL)a[j]);
                tmp += mn;
            }
        }

        if(tmp > mx)
        {
            mx = tmp;
            q = 1;
        }else if(tmp == mx) q++;

        if(q == m)
        {
            for(int i(0);i < n;i++) cout << a[i] << ' ';
            cout << '\n';
            return true;
        }

    }while(next_permutation(ALL(a)));

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}