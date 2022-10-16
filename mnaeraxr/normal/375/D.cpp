#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int64> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 1000000 + 10;
const int size = 300;

int value[maxn];
vi adj[maxn];
int preorder[maxn], pnt = 0;
int B[maxn], E[maxn];

struct qry{
    int b, e, k, idx;

    bool operator <(const qry &q) const{
        if (b / size == q.b / size) return e < q.e;
        return b < q.b;
    }

} Q[maxn];

void dfs(int s, int p){
    B[s] = pnt;
    preorder[pnt++] = s;

    for (auto u : adj[s]){
        if (u == p) continue;

        dfs(u, s);
    }

    E[s] = pnt;
}

int TOTAL = 0;
int BIT[maxn];
int FREQ[maxn];
int ANS[maxn];

void update(int idx, int v){
    TOTAL += v;

    while (idx < maxn){
        BIT[idx] += v;
        idx += idx & -idx;
    }
}

int query(int idx){
    int answer = 0;
    idx--;
    while (idx){
        answer += BIT[idx];
        idx -= idx & -idx;
    }

    return TOTAL - answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> value[i];

    for (int i = 0; i + 1 < n; ++i){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, -1);

    for (int i = 0; i < q; ++i){
        int u, k; cin >> u >> k;

        Q[i] = {B[u], E[u], k, i};
    }

    sort(Q, Q + q);

    int b = 0, e = 0;

    auto add = [&](int p){
        int c = value[ preorder[p] ];
        if (FREQ[c]) update(FREQ[c], -1);
        FREQ[c]++;
        update(FREQ[c], +1);
    };

    auto remove = [&](int p){
        int c = value[ preorder[p] ];
        update(FREQ[c], -1);
        FREQ[c]--;
        if (FREQ[c]) update(FREQ[c], +1);
    };

    for (int i = 0; i < q; ++i){
        auto cur = Q[i];

        while (b > cur.b)
            add(--b);

        while (e < cur.e)
            add(e++);

        while (b < cur.b)
            remove(b++);

        while (e > cur.e)
            remove(--e);

        ANS[ Q[i].idx ] = query(cur.k);
    }

    for (int i = 0; i < q; ++i)
        cout << ANS[i] << endl;

    return 0;
}