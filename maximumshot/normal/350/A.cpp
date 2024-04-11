#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <algorithm>
#include <queue>

#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define vec vector

typedef long long LL;
typedef unsigned long long ull;
typedef long double LD;

const LL inf = 1000000000ll;
const LL inf64 = inf * inf;
const LL base = inf + 7;    
const double pi = acos(-1.0);

using namespace std;

int Abs(int x) {return (x >= 0?x : -x);}

bool solve()
{
    int n, m;
    
    cin >> n >> m;

    vec<int> a(n), b(m);

    for(int i(0);i < n;i++) cin >> a[i];
    for(int i(0);i < m;i++) cin >> b[i];

    sort(ALL(a));
    sort(ALL(b));

    if(b[0] <= a[n - 1]) {cout << -1 << '\n'; return true;}
    if(b[0] <= a[0] * 2) {cout << -1 << '\n'; return true;}

    cout << max(a[0] * 2, a[n - 1]) << '\n';

    return true;
}

int main()
{
    //while(solve());   
    solve();

    return 0;
}