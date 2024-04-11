#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;
vector<int> v[max_n];
bool vis[max_n];
bool is_edge = false;
bool ispet[max_n];

void DFS(int cur) {
    vis[cur] = 1;
    if (ispet[cur]) is_edge = true;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        is_edge = true;
        if (!vis[to]) {
            DFS(to);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    ll cntpet = 0, cnte = 0;
    int a, b, n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &a, &b);
        --a, --b;
        if (a == b) {
            cntpet++;
            ispet[a] = true;
            continue;
        }
        cnte++;
        v[a].pb(b);
        v[b].pb(a);
    }
    int comp = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;
        is_edge = false;
        DFS(i);
        if (is_edge) {
            comp++;
        }
    }
    if (comp > 1) {
        cout << 0;
        return 0;
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ll sz = v[i].size();
        ans += sz * (sz - 1) / 2;
    }
    ans += cntpet * cnte;
    ans += cntpet * (cntpet - 1) / 2;
    cout << ans;
    return 0;
}