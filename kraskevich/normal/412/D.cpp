#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
#define MP make_pair
#define F first
#define S second

vector<int> od;
const int N = (int)1e5;

vector<int> g[N];
vector<bool> u(N);

void dfs(int v)
{
    u[v] = true;
    for (int to : g[v])
        if (!u[to])
            dfs(to);
    od.push_back(v);
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
    }
    u.assign(n, 0);
    for (int i = 0; i < n; i++)
        if (!u[i])
            dfs(i);
    for (int x : od)
        cout << x + 1 << " ";


    return 0;
}