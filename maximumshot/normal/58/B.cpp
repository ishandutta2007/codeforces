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
    LL n;

    cin >> n;

    set<LL> ans;

    bool f = 1;

    while(f)
    {
        f = 0;
        for(LL i(2);i * i <= n;i++)
        {
            if(n % i) continue;
            ans.insert(-n);
            n /= i;
            f = 1;
            break;
        }
    }

    ans.insert(-n);
    ans.insert(-1);

    for(set<LL>::iterator i = ans.begin();i != ans.end();i++) cout << -(*i) << ' ';

    return true;
}
    
int main()
{
    //while(solve());   
    solve();

    return 0;
}