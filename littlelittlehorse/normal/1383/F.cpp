#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

struct node {
    node *next;
    int where, ll, id;
} *first[10001], a[20011], *point[10001];
    
long long mf = 0;
int n, m, tot = 0, len, q, l, e[10001][2], r[11], vv[10001], w[1000001][2], ml, id[101], 
c[10001], dist[10001], pre[10001], way[10001];
long long f[2001];

inline void makelist(int x, int y, int z) {
    a[++l].where = y;
    a[l].ll = z;  a[l].id = l;
    a[l].next = first[x];
    first[x] = &a[l];
}

bool ok = true;
int iii = 0;

bool check1(int &flu, int &uu) {
    memset(dist, 0, sizeof(dist));
    dist[1] = 1; c[1] = 1;
    for (int k = 1, l = 1; l <= k; l++) {
        int m = c[l];
        for (node *x = first[m]; x; x = x->next)
            if (x->ll && !dist[x->where]) {
                dist[x->where] = dist[m] + 1;
                way[x->where] = x->id;
                if (x->where == n) {
                    ml = dist[n] + 1;
                    int ll = 1 << 30;
                    for (int x = way[n]; x; x = way[a[x ^ 1].where]) {
                        ll = min(ll, a[x].ll);
                        if (ll == 1)
                            break;
                    }
                    mf += ll; uu += ll;
                    for (int x = way[n]; x; x = way[a[x ^ 1].where]) {
                        a[x].ll -= ll;
                        a[x ^ 1].ll += ll;
                        if (!ok) {
                            w[++tot][0] = x; w[tot][1] = -ll;
                            ++flu;
                        }
                    }
                    return true;
                }
                c[++k] = x->where;
            }
    }    
    return false;
}

bool check() {
    memset(dist, 0, sizeof(dist));
    dist[1] = 1; c[1] = 1; point[1] = first[1];
    for (int k = 1, l = 1; l <= k; l++) {
        int m = c[l];
        for (node *x = first[m]; x; x = x->next)
            if (!dist[x->where] && x->ll) {
                dist[x->where] = dist[m] + 1;  
                point[x->where] = first[x->where];
                if (x->where == n) {
                    ml = dist[n] + 1;
                    return true;
                }
                c[++k] = x->where;
            }
    }    
    return false;
}

long long flow(int cur, int &flu, int &uu, long long pre) {
    if (!pre)
        return 0;
    if (cur == n)
        return pre;
    
    node *x = point[cur];
    long long lll = 0;
    for (; x; x = x->next) {
        if (x->ll && dist[x->where] == dist[cur] + 1) {
            long long xxx = flow(x->where, flu, uu, min(pre, 1LL * x->ll));
            if (!xxx)
                continue;
            x->ll -= xxx; a[(x->id) ^ 1].ll += xxx; lll += xxx;
            /*if (!ok) {
                ++flu;
                w[++tot][0] = x->id;
                w[tot][1] = -xxx;
            }*/
            pre -= xxx;
            if (!pre) {
                break;
            }
        }   
    }
    point[cur] = x;
    if (pre)
        dist[cur] = -1;
    return lll;
}

inline dinic(int &flu, int &uu) {
    /*for (; check(); ) {
        long long ff = flow(1, flu, uu, 1LL << 60LL);
        uu += ff; mf += ff;
    }*/
    for (; check1(flu, uu); );
}

inline dinic1(int &flu, int &uu) {
    for (; check(); ) {
        long long ff = flow(1, flu, uu, 1LL << 60LL);
        uu += ff; mf += ff;
    }
}

int gg[11][20011];
inline void soso(int status, int i) {
    f[status] = mf;
    if (i == len + 1)
        return;
    int sx = 0, uu = 0;
    if (i == 1)
        dinic(sx, uu);
    soso(status, i + 1);
    a[id[i] + id[i]].ll = 25; a[id[i] + id[i] + 1].ll = 0;
    int flu = 0;
    ok = false;
    //for (int j = 1; j <= l; j++)
    //    gg[i][j] = a[j].ll;
    dinic(flu, uu);
    soso(status | (1 << (i - 1)), i + 1);
    mf -= uu;
    for (; flu; --flu) {
        a[w[tot][0]].ll -= w[tot][1], 
        a[w[tot][0] ^ 1].ll += w[tot][1], --tot;
    }
    //for (int j = 1; j <= l; j++)
    //    a[j].ll = gg[i][j];
    
    a[id[i] + id[i]].ll = 0; a[id[i] + id[i] + 1].ll = 0;
}

inline void soso1(long long &ans, int status, long long cur, int i) {
    if (i == len + 1) {
        ans = min(ans, f[status] + cur);
        return;
    }
    soso1(ans, status | (1 << (i - 1)), cur, i + 1);
    soso1(ans, status, cur + r[id[i]], i + 1);
}

int main() {
    scanf("%d%d%d%d", &n, &m, &len, &q);
    memset(first, 0, sizeof(first)); l = 1;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        makelist(x, y, z);
        makelist(y, x, 0);
        e[i][0] = x; e[i][1] = y;
    }
    memset(f, 255, sizeof(f));
    for (int i = 1; i <= len; i++)
        id[i] = i;
    random_shuffle(id + 1, id + len + 1);
    soso(0, 1);
    
    for (; q--; ) {
        for (int i = 1; i <= len; i++)
            scanf("%d", &r[i]);
        long long ans = 1LL << 60LL;
        soso1(ans, 0, 0, 1);
        printf("%d\n", ans);
    }
}