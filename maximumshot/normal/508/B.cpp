#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = (1ll << 62);    
const double pi = acos(-1.0);

using namespace std;

LL Abs (LL x) {return (x >= 0ll?x : -x);}

bool solve()
{
    string a;

    cin >> a;

    int n = (int)a.size();

    for(int i(0);i < n - 1;i++)
    {
        int x = a[i] - '0';
        int y = a[n - 1] - '0';
        if(x % 2 == 0 && x < y)
        {
            swap(a[i], a[n - 1]);
            cout << a << '\n';
            return true;
        }
    }
    
    for(int i(n - 2);i >= 0;i--)
    {
        int x = a[i] - '0';
        int y = a[n - 1] - '0';
        if(x % 2 == 0 && x > y)
        {
            swap(a[i], a[n - 1]);
            cout << a << '\n';
            return true;
        }
    }

    cout << -1 << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}