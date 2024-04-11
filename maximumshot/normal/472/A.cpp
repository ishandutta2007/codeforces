#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <stack>
#include <stdio.h>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;

const LL inf = 1000000000;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = 1000000007;

using namespace std;

bool solve()
{
    LL n;

    cin >> n;

    if(n % 2) cout << 9 << ' ' << n - 9 << '\n';
    else cout << 4 << ' ' << n - 4 << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}