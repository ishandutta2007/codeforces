#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<int, int> pii;

const ll INF = (ll)1e18;
const int N = 200 * 1000 + 100;

vector<int> g[N];
ll ans = -INF;
ll val[N];
ll sum[N];

ll dfs(int v, int par) {
    vector<ll> kids;
    sum[v] = val[v];
    for (int to : g[v])
        if (to != par) {
            kids.push_back(dfs(to, v));
            sum[v] += sum[to];
        }
    sort(kids.begin(), kids.end());
    reverse(kids.begin(), kids.end());
    if (kids.size() >= 2)
        ans = max(ans, kids[0] + kids[1]);
    if (kids.size())
        return max(sum[v], kids[0]);
    return sum[v];
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> val[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }    
    dfs(0, 0);
    if (ans == -INF)
        cout << "Impossible" << endl;
    else
        cout << ans << endl;
}