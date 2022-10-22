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
    int mx, mn, cnt = 0;
    string a;

    mx = 0, mn = 0;

    cin >> a;

    for(int i(0);i < (int)a.size();i++)
    {
        if(a[i] == '+') cnt++;
        else cnt--;
        mx = max(mx, cnt);
        mn = min(mn, cnt);
    }

    cout << mx - mn << '\n';

    return true;
}
    
int main()
{
    //while(solve());   
    solve();

    return 0;
}