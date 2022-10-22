#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    int n, m;

    cin >> n >> m;

    cout << min(n, m) + 1 << '\n';

    for(int i(0);i < min(n, m) + 1;i++) cout << i << ' ' << min(n, m) - i << '\n';
    
    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}