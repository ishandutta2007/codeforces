#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
 
#define f first
#define s second
#define pb push_back
#define mp make_pair
 
const int maxn = 200500;
const int inf = 1e9;
const double eps = 1e-8;
const int base = 1073676287;

set <int> edge[maxn];
set <int> unused;
vector <int> ans;
int timer = 0;

void dfs(int v) {
    // cerr << v << '\n';
    ++timer;
    unused.erase(v);
    int to = 1;
    while (to < maxn) {
        auto it = unused.lower_bound(to);
        if (it == unused.end())
            break;
        to = *it + 1;
        if (edge[v].find(*it) == edge[v].end())
            dfs(*it);
    }
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    
    int n, m;
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf ("%d%d", &u, &v);
        edge[u].insert(v);
        edge[v].insert(u);
    }
    for (int i = 1; i <= n; ++i)
        unused.insert(i);

    while (!unused.empty()) {
        int v = *unused.begin();
        dfs(v);
        ans.pb(timer);
        timer = 0;
    }
    sort(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int x : ans)
        printf("%d ", x);
}