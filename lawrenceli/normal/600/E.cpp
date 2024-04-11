#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 100100;

int n, c[maxn], sub[maxn];
vector<int> adj[maxn];

void dfs0(int v, int p = -1) {
    sub[v] = 1;
    for (int i : adj[v])
        if (i != p)
            dfs0(i, v), sub[v] += sub[i];
}

vector<int>* vf[maxn];
int freq[maxn];
int mf;
ll sf;

ll ans[maxn];

void upd(int x) {
    freq[x]++;
    if (freq[x] > mf) mf = freq[x], sf = x;
    else if (freq[x] == mf) sf += x;
}

void dfs(int v, int p = -1) {
    int hc = -1;
    for (int i : adj[v])
        if (i != p && (hc == -1 || sub[i] > sub[hc]))
            hc = i;

    //cout << v << ' ' << hc << endl;
    for (int i : adj[v])
        if (i != p && i != hc) {
            dfs(i, v);
            for (int j : (*vf[i]))
                freq[j]--;
            mf = sf = 0;
        }

    if (hc != -1) {
        dfs(hc, v);
        vf[v] = vf[hc];
    } else vf[v] = new vector<int>();

    vf[v]->push_back(c[v]);
    upd(c[v]);

    for (int i : adj[v])
        if (i != p && i != hc) {
            for (int j : (*vf[i])) {
                vf[v]->push_back(j);
                upd(j);
            }
        }

    ans[v] = sf;
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs0(1);
    dfs(1);

    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
}