#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 500111, max_log = 22, inf = 1000111222;
vector<int> v[max_n];
int pr[max_n][max_log];
int tin[max_n];
int tout[max_n];
vector<pair<int, int> > query;

int curtime = 0;

void dfs(int cur, int pred) {
    if (cur != 0) {
        pr[cur][0] = pred;
        int l = 0;
        while (pr[pr[cur][l]][l] != -1) {
            pr[cur][l + 1] = pr[pr[cur][l]][l];
            ++l;
        }
    }
    tin[cur] = curtime++;
    for (int i = 0; i < v[cur].size(); ++i) {
        int to = v[cur][i];
        if (to == pred) continue;
        dfs(to, cur);
    }
    tout[cur] = curtime++;
}

bool is_anc(int a, int b) {
    if (a == -1) {
        return true;
    }
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
    if (is_anc(a, b)) return a;
    if (is_anc(b, a)) return b;
    for (int l = max_log; l > 0; --l) {
        if (!is_anc(pr[a][l - 1], b)) {
            a = pr[a][l - 1];
        }
    }
    return pr[a][0];
}

int main()
{
    //freopen("lca.in", "r", stdin);
    //freopen("lca.out", "w", stdout);
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        ans += a / k;
        if (a % k) {
            ++ans;
        }
    }
    if (ans % 2 == 0) {
        cout << ans / 2;
    } else {
        cout << ans / 2 + 1;
    }
    return 0;
}