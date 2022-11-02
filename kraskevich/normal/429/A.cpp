#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long LL;
typedef long double ld;
#define MP make_pair
#define F first
#define S second

const int INF = 1000 * 1000 * 1000;
const int N = (int)2e5;

vector<int> g[N];
vector<bool> u;
int init[N];
int want[N];
vector<int> ans;

void dfs(int v, int now, int old)
{
    u[v] = true;
    init[v] ^= now;
    if (init[v] != want[v])
    {
        ans.push_back(v);
        now ^= 1;
    }
    for (int to : g[v])
        if (!u[to])
            dfs(to, old, now);

}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        cin >> init[i];
    for (int i = 0; i < n; i++)
        cin >> want[i];
    u.assign(n, 0);
    dfs(0, 0, 0);
    cout << ans.size() << "\n";
    for (int x : ans)
        cout << x + 1 << "\n";

    return 0;
}