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
    int n;

    cin >> n;

    int c[2][2] = {0};

    for(int t, x, y, i(0);i < n;i++)
    {
        cin >> t >> x >> y;
        c[t - 1][0]++;
        c[t - 1][1] += x;
    }

    for(int i(0);i < 2;i++)
        cout << (c[i][1] >= c[i][0] * 5?"LIVE\n" : "DEAD\n");

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}