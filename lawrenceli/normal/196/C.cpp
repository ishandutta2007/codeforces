#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;

const int maxn = 1505;

int n;
vector<int> adj[maxn];
int ans[maxn];
int sze[maxn];

void dfs0(int cur, int p = -1) {
    sze[cur] = 1;
    for (int i : adj[cur])
        if (i != p) {
            dfs0(i, cur);
            sze[cur] += sze[i];
        }
}

int sx, sy;

bool cmp(piii p1, piii p2) {
    return ll(p1.A.B - sy) * (p2.A.A - sx) < ll(p2.A.B - sy) * (p1.A.A - sx);
}

void dfs(int cur, vector<piii> v, int par = -1) {
    int k = 0;
    for (int i = 0; i < v.size(); i++)
        if (v[i].A.A < v[k].A.A)
            k = i;

    ans[v[k].B] = cur;

    sx = v[k].A.A, sy = v[k].A.B;
    v.erase(v.begin() + k);
    sort(v.begin(), v.end(), cmp);

    int p = 0;
    for (int i : adj[cur]) {
        if (i == par) continue;
        vector<piii> w (sze[i]);
        for (int j = 0; j < sze[i]; j++)
            w[j] = v[p++];
        dfs(i, w, cur);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<piii> v (n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].A.A >> v[i].A.B;
        v[i].B = i;
    }

    dfs0(1);
    dfs(1, v);

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}