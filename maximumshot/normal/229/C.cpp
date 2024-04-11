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
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

bool solve() {
    
    int n, m;

    scanf("%d %d", &n, &m);

    vec< int > a(n + 1);

    for(int i = 0;i < m;i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        a[u]++;
        a[v]++;
    }

    ll ans = 0;

    for(int i = 1;i <= n;i++) ans += ll(a[i]) * ll(n - 1 - a[i]); 

    ans = 1ll * n * (n - 1) * (n - 2) / 6 - ans / 2;

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}