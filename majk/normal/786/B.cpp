#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define x first
#define y second

template<typename T> using minheap = priority_queue<T, vector<T>, greater<T>>;

int M;
vector<vector<pii>> W;

void put(int I, int L, int R, int l, int r, bool in, int t, int w) {
    if (l <= L && r >= R) {
        if (in) W[M+t].emplace_back(I,w);
        else W[2*M+I].emplace_back(M+t,w);
        return;
    }
    if (l >= R || r <= L) return;
    put(2*I, L, (L+R)/2, l, r, in, t, w);
    put(2*I+1, (L+R)/2, R, l, r, in, t, w);
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, E, S; cin >> N >> E >> S;
    --S;
    M = 1;
    while (M < N) M *= 2;
    W.resize(4*M);
    for (int i = 1; i < M; ++i) {
        W[i].emplace_back(2*i, 0);
        W[i].emplace_back(2*i+1, 0);
        W[2*M + 2*i].emplace_back(2*M + i, 0);
        W[2*M + 2*i + 1].emplace_back(2*M + i, 0);
    }
    
    for (int i = 0; i < N; ++i) {
        W[M+i].emplace_back(3*M+i, 0);
    }

    for (int i = 0; i < E; ++i) {
        int t; cin >> t;
        if (t == 1) {
            int u,v,w; cin >> u >> v >> w;
            --u; --v;
            W[M+u].emplace_back(M+v, w);
        } else if (t == 2) {
            int u,l,r,w; cin >> u >> l >> r >> w;
            --u; --l;
            put(1, 0, M, l, r, true, u, w);
        } else {
            int v,l,r,w; cin >> v >> l >> r >> w;
            --v; --l;
            put(1, 0, M, l, r, false, v, w);
        }
    }


    vector<ll> D(4*M, ll(1e18));
    minheap<pair<ll,int>> Q;
    Q.push({0, S+M});
    D[S+M] = 0;
    while (!Q.empty()) {
        auto q = Q.top(); Q.pop();
        if (D[q.y] != q.x) continue;
        for (pii e: W[q.y]) {
            if (D[e.x] > e.y + q.x) {
                D[e.x] = e.y + q.x;
                Q.push({D[e.x], e.x});
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        ll d = D[i+M];
        cout << (d < 1e17?d:-1) << " \n"[i==N-1];
    }
}