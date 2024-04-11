#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct node {
    int x, y, pos;
    bool operator < (const node &A) const {
        return x < A.x; 
    }
} q[200001];
bool b[1000001];
int ans[200001], n, m, len, c[100001], a[200001], Left[1000001], ny[1000001];
vector<int> w[200001], idx[1000001];
int p = 1000000007;
long long v[1000001], r[200001], f[200001];

int rp(long long now, int k) {
    long long will = 1;
    for (; k; k >>= 1, now *= now, now %= p)
        if (k & 1) will *= now, will %= p;
    return will;
}

inline void insert(int x, int y) {
    //printf("ins %d %d\n", x, y);
    for (; x <= n; x += x & (-x)) f[x] *= y, f[x] %= p;
}

long long calc(int x) {
    long long will = 1;
    for (; x; x -= x & (-x)) will *= f[x], will %= p;
    return will;
}

int main() {
    //freopen("d.in", "r", stdin);
    //freopen("d.out", "w", stdout);
    memset(b, false, sizeof(b)); b[1] = true;
    len = 0;
    for (int i = 2; i <= 1000000; i++) {
        if (!b[i]) c[++len] = i; 
        for (int j = 1; j <= len; j++)
            if (c[j] * i > 1000000) break;
            else {
                b[c[j] * i] = true;
                if (!(i % c[j])) break;
            }
    }
    for (int i = 2; i <= 1000000; i++) idx[i].clear(), ny[i] = rp(i, p - 2), v[i] = (1 - ny[i] + p) % p, ny[i] = rp(v[i], p - 2);
    scanf("%d", &n); 
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        w[i].clear();
        int k = a[i];
        for (int j = 1; j <= len && j * j <= k; ++j) {
            if (!(k % c[j])) w[i].push_back(c[j]), idx[c[j]].push_back(i);
            for (; !(k % c[j]); k /= c[j]);
        }
        if (k != 1) w[i].push_back(k), idx[k].push_back(i);
    }
    r[0] = 1;
    for (int i = 1; i <= n; i++) r[i] = (r[i - 1] * a[i]) % p;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) scanf("%d%d", &q[i].x, &q[i].y), q[i].pos = i;
    sort(q + 1, q + m + 1);
    for (int i = 1; i <= n; i++) f[i] = 1;
    for (int i = 1; i <= 1000000; i++) 
        if (idx[i].size()) insert(idx[i][0], v[i]);
    int L = 1;
    for (int i = 1; i <= n; i++) {
        for (; L <= m && q[L].x == i; L++) {
            //printf("query %I64d %d %d %d\n", calc(q[L].y), q[L].pos, q[L].y, r[q[L].y] % p * rp(r[q[L].x - 1], p - 2) % p);
            ans[q[L].pos] = calc(q[L].y) * r[q[L].y] % p * rp(r[q[L].x - 1], p - 2) % p;
        }
        for (int j = 0; j < w[i].size(); j++) {
            insert(i, ny[w[i][j]]);
            //printf("%d %d\n", i, w[i][j]);
            if (Left[w[i][j]] + 1 < idx[w[i][j]].size()) 
                insert(idx[w[i][j]][++Left[w[i][j]]], v[w[i][j]]);
                //printf("%d\n", idx[w[i][j]][Left[w[i][j]]]);
        }
        //printf("6 %I64d\n", calc(6));
    }
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
}