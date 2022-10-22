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

    for(int i(n / 7);i >= 0;i--)
    {
        int q = n - i * 7;
        if(q % 4) continue;

        for(int j(0);j < q / 4;j++) cout << 4;
        for(int j(0);j < i;j++) cout << 7;
        return true;
    }

    cout << -1 << '\n';

    return true;
}

int main()
{
    //while(solve()) {}
    solve();

    return 0;
}