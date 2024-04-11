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
    LL n, m, a, b;

    cin >> n >> m >> a >> b;

    if(a * m <= b) cout << n * a << '\n';
    else cout << (n / m) * b + min((n % m) * a, (n % m != 0) * b) << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}