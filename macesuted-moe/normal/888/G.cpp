/*
 * Time Limit :     2 sec
 * Memory Limit :   256 MB
 */

#pragma GCC optimize("Ofast,fast-math,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

namespace IO {
const int sz = 1 << 20;
char b[sz + 5], *t = b, p[105];
inline char gc() {
    return getchar();
}
template <class T>
inline T gi() {
    T ret = 0;
    char c = gc();
    int f = 1;
    for (; c < '0' || c > '9'; c = gc())
        if (c == '-') f = -1;
    for (; c >= '0' && c <= '9'; c = gc())
        ret = (ret << 3) + (ret << 1) + (c ^ 48);
    return ret * f;
}
template <class T>
inline void gi(T& ret) { ret = gi<T>(); }
inline void flush() { fwrite(b, 1, t - b, stdout), t = b; }
inline void pc(char x) {
    *t++ = x;
    if (t - b == sz) flush();
}
template <class T>
inline void pi(T x, char c = '\n') {
    if (x < 0) x = -x, pc('-');
    if (x == 0) pc('0');
    int t = 0;
    for (; x; x /= 10) p[++t] = x % 10 + '0';
    for (; t; --t) pc(p[t]);
    pc(c);
}
struct F {
    ~F() { flush(); }
} f;
}  // namespace IO
using IO::gi;
using IO::pi;

#define reg register

const int maxn = 2e5 + 5;
const int maxBiglgn = 31;

long long a[maxn];
int n, m;

int trie[maxn * maxBiglgn][2], back = 0, vis[maxn * maxBiglgn], fini[maxn * maxBiglgn];
bool num[maxn][maxBiglgn + 5];

void insert(int& p, int node, int dep = maxBiglgn - 1) {
    vis[p ? p : p = ++back]++;
    (~dep) ? insert(trie[p][a[node] >> dep & 1], node, dep - 1) : (fini[p] = node, void());
    return;
}

void erase(int p, int node, int dep = maxBiglgn - 1) {
    vis[p]--;
    if (~dep) erase(trie[p][a[node] >> dep & 1], node, dep - 1);
    return;
}

int find(int p, int node, int dep = maxBiglgn - 1) {
    if (!~dep) return fini[p];
    return find(vis[trie[p][a[node] >> dep & 1]] ? trie[p][a[node] >> dep & 1] : trie[p][(a[node] >> dep & 1) ^ 1], node, dep - 1);
}

struct Edge {
    long long dist;
    int from, to;
};

int fa[maxn];
Edge edge[maxn];
vector<int> ver[maxn];

int getFa(int k) {
    while (k != fa[k]) k = fa[k] = fa[fa[k]];
    return k;
}

void merge(vector<int>& va, vector<int>& vb) {
    if (!vb.empty()) {
        if (va.size() < vb.size()) swap(va, vb);
        va.insert(va.end(), vb.begin(), vb.end());
        vb.clear();
    }
    return;
}

long long Boruvka() {
    long long answer = 0;
    int root = 0;
    for (reg int i = 1; i <= n; i++) insert(root, fa[i] = i), ver[i].emplace_back(i);
    for (reg int block = n; block > 1;) {
        for (reg int i = 1; i <= n; i++)
            if (!ver[i].empty()) {
                for (auto j : ver[i]) erase(root, j);
                edge[i] = (Edge){0x7fffffff, -1, -1};
                for (auto j : ver[i]) {
                    int cac = find(root, j);
                    if ((a[cac] ^ a[j]) < edge[i].dist) edge[i] = (Edge){a[cac] ^ a[j], j, cac};
                }
                for (auto j : ver[i]) insert(root, j);
            }
        for (reg int i = 1; i <= n; i++)
            if (!ver[i].empty()) {
                int x = getFa(edge[i].from), y = getFa(edge[i].to);
                if (x != y) {
                    fa[x] = y;
                    answer += edge[i].dist;
                    merge(ver[y], ver[x]);
                    block--;
                }
            }
    }
    return answer;
}

int main() {
    n = gi<int>();
    for (reg int i = 1; i <= n; i++) a[i] = gi<long long>();
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    long long answer;
    printf("%lld\n", answer = Boruvka());
    return 0;
}