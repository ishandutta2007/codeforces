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
    int n, t;

    cin >> n >> t;

    string a;

    cin >> a;

    while(t--)
    {
        for(int i(0);i < (int)a.size() - 1;i++)
        {
            if(a[i] == 'B' && a[i + 1] == 'G')
                swap(a[i], a[i + 1]), i++;
        }
    }

    cout << a << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}