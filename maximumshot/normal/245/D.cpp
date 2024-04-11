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

bool solve()
{
    int n;

    cin >> n;

    vec< vec<LL> > mat(n, vec<LL>(n));
    vec<LL> ans(n, 0);
    
    for(int i(0);i < n;i++)
        for(int j(0);j < n;j++)
            cin >> mat[i][j];

    for(int i(0);i < n;i++)
    {
        for(int j(0);j < n;j++)
        {
            if(i == j) continue;
            ans[j] |= mat[i][j];
        }
    }

    for(int i(0);i < n;i++) cout << ans[i] << ' ';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}