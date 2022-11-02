#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define A first
#define B second

const int maxn = 200100;

int n, ar[maxn];
vector<int> adj[maxn];

vector<int> vdiv;
int dval[maxn][20];

void init() {
    int x = ar[1];
    for (int k = 2; k < maxn; k++) {
        if (x % k == 0) vdiv.push_back(k);
        while (x % k == 0) x /= k;
    }
    assert(vdiv.size() < 20);

    for (int i = 1; i <= n; i++) {
        x = ar[i];
        for (int j = 0; j < vdiv.size(); j++) {
            int k = vdiv[j];
            int p = 1;
            while (x % k == 0) x /= k, p *= k;
            dval[i][j] = p;
        }
    }
}

int ans[maxn];
set<pair<int, int> > st[20];

void ins(int v) {
    for (int i = 0; i < vdiv.size(); i++)
        st[i].insert(MP(dval[v][i], v));
}

void del(int v) {
    for (int i = 0; i < vdiv.size(); i++)
        st[i].erase(MP(dval[v][i], v));
}

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int getans() {
    int x = 1;
    vector<pair<int, int> > v;
    for (int i = 0; i < vdiv.size(); i++) {
        auto it = st[i].begin();
        v.push_back(MP(it->B, i));
        x *= it->A;
    }

    int ret = x;
    sort(v.begin(), v.end());
    for (int i = 0, j; i < v.size(); i = j) {
        int cur = x;
        for (j = i; j < v.size() && v[j].A == v[i].A; j++) {
            auto it = st[v[j].B].begin();
            cur /= it->A;
            it++;
            cur *= it->A;
        }
        ret = max(ret, cur);
    }
    return ret;
}

void dfs(int v, int p, int d) {
    ins(v);
    d = gcd(d, ar[v]);

    ans[v] = max(d, getans());

    for (int i : adj[v])
        if (i != p) {
            dfs(i, v, d);
        }

    del(v);
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> ar[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    init();

    ans[1] = ar[1];
    ins(1);
    for (int i : adj[1]) {
        dfs(i, 1, 0);
    }

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}