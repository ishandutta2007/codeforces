#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <iomanip>

#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <cstring>
#include <tuple>
#include <map>
#include <queue>
#include <bitset>
#include <list>
#include <stack>
#include <unordered_map>
#include <array>

#include <complex>
#include <time.h>
#include <math.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;
typedef pair< double, double > pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;

struct Dsu {
    int n;
    vec< int > p, h;

    Dsu() {
        n = 0;
    }

    Dsu(int n) : n(n) {
        p.resize(n + 1);
        h.resize(n + 1);
        for(int i = 1;i <= n;i++) p[i] = i;
    }

    int find(int x) { return (p[x] == x?x : p[x] = find(p[x])); }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return 0;
        if(h[x] == h[y]) h[x]++, p[y] = x;
        else {
            if(h[x] < h[y]) swap(x, y);
            p[y] = x;
        }
        return 1;
    }
};

int n;
vec< int > p;

bool solve() {

    scanf("%d", &n);

    Dsu dsu(n);

    p.resize(n + 1, -1);

    int ok = 0;
    int f = -1;

    for(int x, i = 1;i <= n;i++) {
        scanf("%d", &x);
        if(x == i) {
            if(!ok) ok = 1, f = i;
            continue;
        }
        // add edge {x, i}
        if(dsu.merge(x, i)) {
            p[i] = x;
        }
    }

    int res = 0;

    vec< int > ps;

    for(int i = 1;i <= n;i++) if(p[i] == -1) ps.push_back(i);

    if(!ok) {
        p[ps[0]] = ps[0];
        res++;
    }else {
        p[f] = f;
    }

    for(int u, v, i = 0;i + 1 < (int)ps.size();i++) {
        u = ps[i];
        v = ps[i + 1];
        if(p[u] == -1) p[u] = v;
        else p[v] = u;
        res++;
    }

    printf("%d\n", res);
    for(int i = 1;i <= n;i++) printf("%d ", p[i]);
    printf("\n");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}