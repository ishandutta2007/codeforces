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

int cnt(LL x)
{
    int ans = 0;

    while(x) {ans += (x % 10 == 4 || x % 10 == 7), x /= 10;}

    return ans;
}

bool lucky(LL x)
{
    if(!x) return false;

    while(x)
    {
        if(x % 10 != 4 && x % 10 != 7)  return false;
        x /= 10;
    }
    
    return true;
}

bool solve()
{
    LL x;

    cin >> x;

    cout << (lucky(cnt(x))?"YES\n" : "NO\n");
    
    return true;
}

int main()
{
    //while(solve()) {}
    solve();

    return 0;
}