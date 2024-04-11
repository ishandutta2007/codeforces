#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111;
// to, is_equal
vector<pair<int, bool> > v[max_n];
int r[max_n];
vector<int> per[max_n];
bool vis[max_n];
int color[max_n];

void dfs(int cur)
{
    for (pair<int, int> p : v[cur]) {
        int to = p.F;
        bool eqv = p.S;
        if (vis[to]) {
            if (eqv && color[cur] != color[to] ||
                !eqv && color[cur] == color[to]) {
                    cout << "NO";
                    exit(0);
                }
        }
        else {
            int other = color[cur] == 1 ? 2 : 1;
            if (eqv) color[to] = color[cur];
            else color[to] = other;
            vis[to] = true;
            dfs(to);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        scanf("%d", r + i);
    }
    int cnt, door;
    for (int i = 0; i < m; ++i) {
        scanf("%d", &cnt);
        for (int j = 0; j < cnt; ++j) {
            scanf("%d", &door);
            door--;
            per[door].pb(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        int a = per[i][0], b = per[i][1];
        v[a].pb(mp(b, r[i]));
        v[b].pb(mp(a, r[i]));
    }
    for (int i = 0; i < m; ++i) {
        if (!vis[i]) {
            vis[i] = 1;
            color[i] = 1;
            dfs(i);
        }
    }
    cout << "YES\n";
    return 0;
}