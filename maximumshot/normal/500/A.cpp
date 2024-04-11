#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <stdio.h>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef long double LD;
typedef unsigned long long ull;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const double pi = acos(-1.0);
const LL base = inf + 7;

using namespace std;

bool solve()
{
    int n, t;

    cin >> n >> t;

    vec<int> a(n);

    for(int i(1);i <= n - 1;i++) cin >> a[i];

    int pos = 1;

    while(pos < n)
    {
        if(pos == t) {cout << "YES\n"; return true;}
        pos += a[pos];
    }

    if(pos != t) cout << "NO\n";
    else cout << "YES\n";

    return true;
}

int main()
{
    //while(solve());
    solve();

    return 0;
}