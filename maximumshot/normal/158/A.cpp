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
    int n, k;

    cin >> n >> k;

    vec<int> a(n);

    for(int i(0);i < n;i++) cin >> a[i];

    for(int i(0);i < n;i++)
    {
        if(a[i] < a[k - 1] || a[i] == 0)
        {
            cout << i << '\n';
            return true;
        }
    }

    cout << n << '\n';

    return true;
}

int main()
{
    //while(solve()) {}
    solve();

    return 0;
}