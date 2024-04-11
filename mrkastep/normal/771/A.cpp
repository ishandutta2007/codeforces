#pragma warning (disable: 4996)
#include <iostream> 
#include <stdio.h> 
#include <cstdio> 
#include <algorithm> 
#include <vector> 
#include <map> 
#include <set> 
#include <string> 
#include <cstring> 
#include <valarray> 
#include <tuple> 
#include <complex> 
#include <bitset> 
#include <assert.h> 
#include <unordered_map>
#include <queue>

#define pb push_back 
#define mp make_pair 

typedef long long ll;

using namespace std;

ll n, m, p[200005], e[200005], c[200005];

ll find(ll v) {
    if (p[v] == v) {
        return p[v];
    }
    return (p[v] = find(p[v]));
}

void unit(ll v1, ll v2) {
    ll p1, p2;
    p1 = find(v1);
    p2 = find(v2);
    if (p1 == p2) {
        e[p1]++;
    } else {
        e[p1] += e[p2] + 1;
        c[p1] += c[p2];
    }
    p[p2] = p1;
}

void solve() {
    ll i, j, a, b;
    for (i = 0; i < 200005; i++) {
        p[i] = i;
        e[i] = 0;
        c[i] = 1;
    }
    for (i = 0; i < m; i++) {
        scanf("%I64d%I64d", &a, &b);
        a--;
        b--;
        unit(a, b);
    }
    for (i = 0; i < n; i++) {
        if (i == find(i)) {
            if (e[i] != c[i] * (c[i] - 1) / 2) {
                printf("NO");
                return;
            }
        }
    }
    printf("YES");
    return;
}

int main() {
#ifdef _DEBUG 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
    scanf("%I64d%I64d", &n, &m);
    solve();
    return 0;
}