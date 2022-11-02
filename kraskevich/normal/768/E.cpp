#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int N = 66;

map<ull, int> g[N];

int getg(ull mask, int n) {
    if (n == 0)
        return 0;
    if (g[n].count(mask))
        return g[n][mask];
    int& res = g[n][mask];
    res = 0;
    set<int> was;
    for (int i = 1; i <= n; i++)
        if (!(mask & (ull(1) << i))) 
            was.insert(getg(mask | (ull(1) << i), n - i));
    while (was.count(res))
        res++;
    return res;
}

int main() {
#ifdef LOCAL
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    vector<int> f(66);
    for (int i = 1; i <= 60; i++)
        f[i] = getg(0, i);
    int n;
    scanf("%d", &n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        //cerr << x << " " << f[x] << endl;
        res ^= f[x];
    }
    puts(res == 0 ? "YES" : "NO");
}