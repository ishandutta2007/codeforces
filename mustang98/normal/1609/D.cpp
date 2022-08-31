#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

vector<int> v[max_n];
vector<int> comp;
bool vis[max_n];
void dfs(int cur) {
    vis[cur] = 1;
    comp.PB(cur);
    for (int to : v[cur]) {
        if (!vis[to]) {
            dfs(to);
        }
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    for (int step = 0; step < d; ++step) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        v[a].PB(b);
        v[b].PB(a);
        vector<int> sz;
        int dop = 0;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue;
            comp.clear();
            dfs(i);
            int cnte = 0;
            int cntv = comp.size();
            for (int x : comp) {
                cnte += v[x].size();
            }
            cnte /= 2;
            dop += (cnte - (cntv - 1));
            sz.push_back(cntv);
        }
        sort(sz.begin(), sz.end());
        int ans = 0;
        ++dop;
        dop = min<int>(sz.size(), dop);
        sort(sz.begin(), sz.end());
        for (int i = 0; i < dop; ++i) {
            ans += sz.back();
            sz.pop_back();
        }
        cout << ans - 1<< "\n";
    }

    return 0;
}