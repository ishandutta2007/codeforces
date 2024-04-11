#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct RQV {
    int a, i, s;
};
struct RQRV {
    int a;
};

struct RQ {
    static RQV Zero() { return RQV{ 1000000,0,0 }; }
    static RQRV RZero() { return RQRV{ 0 }; }
    // addition
    static RQV f(RQV a, RQV b) {
        RQV res = (a.a < b.a) ? a : b;
        res.s = a.s + b.s;
        return res;
    }
    // update function
    static void uf(RQV& a, RQV b) { a = b; }
    // effect of range queries n-sized
    static void ef(RQV& a, RQRV b, int n) { a.a -= b.a; }
    // range query update
    static void ruf(RQRV& a, RQRV b) { a.a += b.a; }
    struct Node {
        RQV v; RQRV r;
    };
    int N;
    vector<Node> V;

    void init(int n) {
        N = 1; while (N < n) N *= 2;
        V.assign(N * 2, { Zero(),RZero() });
    }

    void spread(int i, int z) {
        if (z != 1) {
            ef(V[i * 2].v, V[i].r, z / 2);
            ruf(V[i * 2].r, V[i].r);
            ef(V[i * 2 + 1].v, V[i].r, z / 2);
            ruf(V[i * 2 + 1].r, V[i].r);
        }
        V[i].r = RZero();
    }

    void updp(int p, RQV v) {
        p += N; uf(V[p].v, v); ef(V[p].v, V[p].r, 1);
        int z = 1;
        while (p != 1) {
            p /= 2; z *= 2;
            V[p].v = f(V[p * 2].v, V[p * 2 + 1].v);
            ef(V[p].v, V[p].r, z);
        }
    }

    void upd(int l, int r, RQRV v, int a = 0, int b = 0, int i = -1) {
        if (i == -1) { a = 0; b = N; i = 1; }
        spread(i, b - a);
        if (r <= a || b <= l) return;
        if (l <= a && b <= r) {
            ruf(V[i].r, v);
            ef(V[i].v, V[i].r, b - a);
            return;
        }
        upd(l, r, v, a, (a + b) / 2, i * 2);
        upd(l, r, v, (a + b) / 2, b, i * 2 + 1);
        V[i].v = f(V[i * 2].v, V[i * 2 + 1].v);
        ef(V[i].v, V[i].r, b - a);
    }

    RQV query(int l, int r, int a = 0, int b = 0, int i = -1) {
        if (i == -1) { a = 0; b = N; i = 1; }
        if (r <= a || b <= l) return Zero();
        if (l <= a && b <= r) return V[i].v;
        RQV q1 = query(l, r, a, (a + b) / 2, i * 2);
        RQV q2 = query(l, r, (a + b) / 2, b, i * 2 + 1);
        q1 = f(q1, q2);
        ef(q1, V[i].r, min(r, b) - max(l, a));
        return q1;
    }
};

int N, Q;
int A[300000];
RQ G;
vector<pair<int,int>> Que[300000]; // right,idx
int ans[300000];

const RQV usedv = RQV{ 1000000,0,1 };

int main() {
    scanf("%d%d", &N, &Q);
    rep(i, N) scanf("%d", &A[i]);
    G.init(N);
    rep(i, N) {
        A[i] = i + 1 - A[i];
        if (A[i] < 0) A[i] = 1000000;
    }
    rep(i, Q) {
        int l, r; scanf("%d%d", &l, &r);
        Que[l].push_back({ N - r,i });
    }
    for (int l = N - 1; l >= 0; l--) {
        G.updp(l, RQV{ A[l],l,0 });
        while (true) {
            auto q = G.query(0, N);
            if (q.a > 0) break;
            G.updp(q.i, usedv);
            G.upd(q.i, N, RQRV{ 1 });
        }
        for (auto q : Que[l]) {
            ans[q.second] = G.query(l, q.first).s;
        }
    }
    rep(i, Q) printf("%d\n", ans[i]);
    return 0;
}