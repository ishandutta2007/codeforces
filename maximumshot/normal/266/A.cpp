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

    string a;

    cin >> a;

    int ans = 0;

    for(int i(0);i < (int)a.size() - 1;i++)
        if(a[i] == a[i + 1]) ans++;
    
    cout << ans << '\n';

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}