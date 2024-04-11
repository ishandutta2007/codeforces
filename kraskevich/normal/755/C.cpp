#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 100 * 1000;
vector<int> g[N];
bool was[N];

void dfs(int v) {
    was[v] = true;
    for (int to : g[v])
        if (!was[to])
            dfs(to);
} 

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {   
        int p;
        cin >> p;
        p--;
        g[i].push_back(p);
        g[p].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (!was[i]) {
            dfs(i);
            ans++;
        }
    cout << ans << endl;
}