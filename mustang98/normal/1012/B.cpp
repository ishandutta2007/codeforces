#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

vector<int> v[max_n];
pair<int, int> p[max_n];
vector<int> row[max_n];
vector<int> col[max_n];

int n, m, q;

bool compr(int i, int j) {
    return p[i].second < p[j].second;
}

bool compc(int i, int j) {
    return p[i].F < p[j].F;
}

bool vis[max_n];
bool vis0[max_n];

void dfs(int cur) {
    vis[cur] = 1;
    vis0[p[cur].F] = 1;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (!vis[to]) {
            dfs(to);
        }
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    for (int i = 0; i < q; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        p[i] = MP(a, b);
        row[a].PB(i);
        col[b].PB(i);
    }
    for (int i = 0; i < n; ++i) {
        vector<int>& r = row[i];
        sort(r.begin(), r.end(), compr);
        for (int j = 0; j + 1 < r.size(); ++j) {
            int a = r[j];
            int b = r[j + 1];
            v[a].PB(b);
            v[b].PB(a);
        }
    }

    for (int i = 0; i < m; ++i) {
        vector<int>& c = col[i];
        sort(c.begin(), c.end(), compc);
        for (int j = 0; j + 1 < c.size(); ++j) {
            int a = c[j];
            int b = c[j + 1];
            v[a].PB(b);
            v[b].PB(a);
        }
    }
    for (int i = 0; i < q; ++i) {
        if (p[i].second == 0 && !vis[i]) {
            dfs(i);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vis0[i]) continue;
        ans++;
        vis0[i] = 1;
        if (row[i].size()) {
            dfs(row[i][0]);
        }
    }
    for (int j = 1; j < m; ++j) {
        if (col[j].size() == 0) {
            ++ans;
        }
    }
    cout << ans;

    return 0;
}