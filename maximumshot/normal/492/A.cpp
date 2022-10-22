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
const LL base = inf + 7;

using namespace std;

bool solve()
{
    int n;

    cin >> n;

    int sum, ans, delt = 1, all = 0;
    sum = 0, ans = 0;

    while(all < n)
    {
        sum += delt;
        all += sum;
        if(all > n) break;
        delt++; 
        ans++;

        //cout << delt << ' ' << sum << '\n';
    }

    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}