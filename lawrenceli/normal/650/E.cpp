#include <bits/stdc++.h> 

using namespace std;

#define A first
#define B second

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int maxn = 500500;

int n;
vector<int> adj[maxn];
vector<pii> adj2[maxn];

//dsu
int par[maxn], rnk[maxn];

int getpar(int a) { return par[a] == a ? a : par[a] = getpar(par[a]); }
int mergep(int a, int b) {
    if (rnk[a] > rnk[b]) swap(a, b);
    par[a] = b;
    if (rnk[a] == rnk[b]) rnk[b]++;
    return b;
}

//linked list
piii lst[2 * maxn];
int head[maxn], tail[maxn], nxt[2 * maxn], bck[2 * maxn], lsze;

bool U[maxn];

void add(int i, piii p) {
    lst[lsze] = p;
    if (tail[i] == -1) {
        head[i] = tail[i] = lsze;
    } else {
        nxt[tail[i]] = lsze;
        bck[lsze] = tail[i];
        tail[i] = lsze;
    }
    lsze++;
}

void pop(int i) {
    int x = bck[tail[i]];
    if (x == -1) {
        head[i] = tail[i] = -1;
    } else {
        nxt[x] = -1;
        tail[i] = x;
    }
}

void merge(int i, int j) {
    i = getpar(i), j = getpar(j);
    int k = mergep(i, j);
    if (j == k) swap(i, j);

    if (head[j] == -1) return;
    if (head[i] == -1) head[i] = head[j];
    else {
        nxt[tail[i]] = head[j];
        if (head[j] != -1) bck[head[j]] = tail[i];
    }
    tail[i] = tail[j];
}

pii conv(pii p) { return pii(min(p.A, p.B), max(p.A, p.B)); }

pii uplug[maxn], plug[maxn];
int cnt;

void dfs(int v, int p = 0) {
    bool b = 0;
    for (pii i : adj2[v])
        if (i.A == p)
            b = 1;

    for (int i : adj[v])
        if (i != p)
            dfs(i, v);

    if (!b && v != 1) {
        int w = getpar(v);
        piii x;
        while (1) {
            assert(tail[w] != -1);
            x = lst[tail[w]];
            pop(w);
            if (U[x.B]) break;
        }
        U[x.B] = 0;
        uplug[cnt] = pii(v, p);
        plug[cnt] = x.A;
        cnt++;
        merge(x.A.B, v);
    } else merge(p, v);
}

int ea[maxn], eb[maxn];
bool C[maxn];

void dfs0(int v, int p = 0) {
    for (pii x : adj2[v])
        if (x.A == p)
            C[x.B] = 1;

    for (int i : adj[v])
        if (i != p)
            dfs0(i, v);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());

    memset(head, -1, sizeof(head));
    memset(tail, -1, sizeof(tail));
    memset(nxt, -1, sizeof(nxt));
    memset(bck, -1, sizeof(bck));
    for (int i = 1; i <= n; i++) par[i] = i;

    for (int i = 1; i < n; i++) {
        cin >> ea[i] >> eb[i];
        adj2[ea[i]].push_back(pii(eb[i], i));
        adj2[eb[i]].push_back(pii(ea[i], i));
        U[i] = 1;
    }

    dfs0(1);

    for (int i = 1; i < n; i++)
        if (!C[i]) {
            add(ea[i], piii(pii(ea[i], eb[i]), i));
            add(eb[i], piii(pii(eb[i], ea[i]), i));
        }

    dfs(1);

    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << uplug[i].A << ' ' << uplug[i].B << ' ' << plug[i].A << ' ' << plug[i].B << '\n';
}