#include <iostream>
#include <vector>

using namespace std;
#define x first
#define y second
typedef pair<int,int> pii;

int N, M;
vector<int> S, P, D;
vector<int> ChainLength, ChainOffset, Chains;
int HLD;
vector<vector<int>> E, Q;
vector<pii> C;

struct SegTree {
    SegTree(int size) {
        S = 1; while (S < size) S*=2;
        V.resize(2*S);
        fill(V.begin(), V.end(),int(1e8));
    }

    void set(int i, int v) {
        V[i+=S] = v;
        while(i>1) {
            V[i/2] = min(V[i],V[i^1]);
            i/=2;
        }
    }

    int get(int l, int r) {
        return get(1, 0, S, l, r);
    }

    int get(int i, int L, int R, int l, int r) {
        if (l <= L && r >= R) return V[i];
        int M = (L+R)/2;
        if (r <= M) return get(2*i, L, M, l, r);
        if (l >= M) return get(2*i+1, M, R, l, r);
        return min(get(2*i, L, M, l, r), get(2*i+1, M, R, l, r));
    }

    vector<int> V;
    int S;
};

int dfs(int u, int p) {
    P[u] = p;
    S[u] = 1;
    for (int v: E[u]) {
        if (v != p) S[u] += dfs(v, u);
    }
    return S[u];
}

void dfs2(int u, int ch) {
    if (ch == ChainLength.size()) {
        ChainLength.push_back(0);
        ChainOffset.push_back(HLD);
    }
    C[u] = {ch, ChainLength[ch]++};
    Chains[HLD++] = u;
    for (int v: E[u]) if (P[u] != v && 2*S[v] >= S[u]) dfs2(v, ch);
    for (int v: E[u]) if (P[u] != v && 2*S[v] < S[u]) dfs2(v, ChainLength.size());
}

int main() {
    cin >> N >> M;
    HLD = 0;
    S.resize(N);
    E.resize(N);
    C.resize(N);
    P.resize(N);
    D.resize(N);
    Chains.resize(N);
    fill(D.begin(),D.end(),int(1e8));
    for (int i = 0; i < N-1; ++i) {
        int u, v; cin >> u >> v; --u; --v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    dfs(0, -1);
    dfs2(0, 0);
    SegTree LO(N), HI(N);
    LO.set(0, 0);
    HI.set(0, 0);
    D[0] = 0;

    for (int i = 0; i < M; ++i) {
        int t, v; cin >> t >> v; --v;
        if (t == 1) {
            int l = 0;
            while (v != -1) {
                int ch = C[v].x, d = C[v].y;
                if (D[v] <= l) break;
                D[v] = l;
                LO.set(ChainOffset[ch] + d, l-d);
                HI.set(ChainOffset[ch] + d, l+d);
                
                l += d + 1;
                v = P[Chains[ChainOffset[ch]]];
            }
        } else {
            int ans = int(1e8);
            int l = 0;
            while (v != -1) {
                int ch = C[v].x, d = C[v].y;
                ans = min(ans, l + LO.get(ChainOffset[ch], ChainOffset[ch]+d+1) + d);
                ans = min(ans, l + HI.get(ChainOffset[ch] + d, ChainOffset[ch] + ChainLength[ch]) - d);
   
                l += d + 1;
                v = P[Chains[ChainOffset[ch]]];
            }
            cout << ans << '\n';
        }
    }

}