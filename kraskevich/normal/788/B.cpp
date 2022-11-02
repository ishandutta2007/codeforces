#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int N = 1000 * 1000 + 10;

vector<int> g[N];
bool was[N];
ll e;
ll res;

void dfs(int v) {
    was[v] = true;
    for (int to : g[v]) {
        e++;
        if (!was[to])
            dfs(to);
    }
}

ll cnt(ll x) {
    return x * (x - 1) / 2;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    ll loops = 0;
    vector<bool> has_loop(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        if (a != b) 
            g[b].push_back(a);
        else  {
            loops++;
            has_loop[a] = true;
        }
    }
    int comps = 0;
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            e = 0;
            dfs(i);
            if (e > 0)
                comps++;
        }
    if (comps != 1 || m < 2) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
        res += cnt(g[i].size() - has_loop[i]);
    res += loops * (m - loops) + loops * (loops - 1) / 2;
    cout << res << endl;
}