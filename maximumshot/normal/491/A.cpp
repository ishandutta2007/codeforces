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
    LL a, b;

    cin >> a >> b;

    cout << b + 1 << ' ';

    for(int i(b);i >= 1;i--) cout << i << ' ';
    for(int i(b + 2);i <= a + b + 1;i++) cout << i << ' ';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}