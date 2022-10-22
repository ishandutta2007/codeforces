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

vec< int > par, size;

int find( int x ) {
    return ( par[x] == x ? x : par[x] = find(par[x]) );
}

void merge(int x, int y) {
    par[y] = x;
}

bool solve() {
    
    int n, m;

    scanf("%d", &n);

    par.clear();
    size.clear();
    par.resize(n + 1);
    size.resize(n + 1);

    for(int x, i = 0;i < n;i++) scanf("%d", &x), par[i + 1] = i + 1;

    scanf("%d", &m);

    vec< tuple< int, int, int> > s;

    for(int a, b, c, i = 0;i < m;i++) {
        scanf("%d %d %d", &a, &b, &c);
        s.push_back(mt(c, a, b));
    }

    sort(ALL(s));

    ll ans = 0;

    for(int i = 0;i < m;i++) {
        int a, b, c;
        tie(c, a, b) = s[i];
        if(find(a) != find(b) && par[b] == b) {
            ans += c;
            merge(a, b);
        }
    }

    int cnt = 0;

    for(int i = 1;i <= n;i++) {
        if(par[i] == i) cnt++;
    }

    cout << (cnt > 1?-1ll : ans) << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}