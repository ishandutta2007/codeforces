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

    int pos = 0;

    for(int i(0);i < n;i++, pos = (pos + 1) % 4) cout << char(pos + 'a');

    return true;
}

int main()
{
    //while(solve()) {}
    solve();

    return 0;
}