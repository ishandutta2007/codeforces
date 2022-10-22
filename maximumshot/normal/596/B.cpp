#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = acos(-1.0);

inline ll f(ll x) {
    return (x >= 0?x : -x);
}

bool solve()
{
    int n;

    scanf("%d", &n);

    ll ans = 0, last = 0;

    for(int x, i = 1;i <= n;i++) {
        scanf("%d", &x);
        ans += f(last - x);
        last = x;
    }

    cout << ans << '\n';

    return true;
} 

int main() {
    
    //while(solve());
    solve();    

    return 0;
}