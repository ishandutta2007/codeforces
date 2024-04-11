// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e3 + 5;

int n, d, f[N], sz[N], ans = 1, t = 1, now, sum;

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

multiset<int> A, B;


void inline ins(int x) {
    B.insert(x);
}

void inline Del(int x) {
   B.erase(B.find(x));
}

void merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) {
        ++t;
        return;
    }
    Del(sz[x]), Del(sz[y]);
    f[x] = y, sz[y] += sz[x];
    ins(sz[y]);
    chkMax(ans, sz[y]);
}
 
int main() {
    read(n), read(d);
    for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1, ins(1);
    while (d--) {
        int x, y; read(x), read(y);
        merge(x, y);
        vector<int> r;
        int s = 0;
        for (int i = 0; i < t; i++) {
            if (B.size()) {
                int u = *--B.end();
                B.erase(B.find(u));
                s += u;
                r.pb(u);
            }
        }
        for (int v: r) B.insert(v);
        printf("%d\n", s - 1);
    }
    return 0;
}