#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
#define MP make_pair
#define F first
#define S second


const int N = (int)2e5;
vector<int> g[N];
vector<int> h;
vector<bool> u;
long long n, k, p;
vector<long long> sum;

void dfs(int v, int hh)
{
    u[v] = true;
    h.push_back(hh);
    for (int to : g[v])
        if (!u[to])
            dfs(to, hh + 1);
}

long long solve(int pos) {
    int l = 1;
    int r = min((long long)pos, k);
    while (l < r) {
        int m = (l + r + 1) / 2;
        long long s = sum[pos] - sum[pos - m];
        if (h[pos] * 1ll * m - s <= p)
            l = m;
        else
            r = m - 1;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> k >> p;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if (k == 0)
    {
        cout << 0;
        return 0;
    }
    u.assign(n, 0);
    dfs(0, 0);
    sort(h.begin(), h.end());
    sum.push_back(h[0]);
    for (int i = 1; i < n; i++)
        sum.push_back(sum[i - 1] + h[i]);
    long long res = 0;
    for (int i = 1; i < n; i++)
        res = max(res, solve(i));
    cout << res;

    return 0;
}