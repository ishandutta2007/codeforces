#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define MAXN (1<<20)
#define MOD 1000000007
#define N 1048576
ll n, x, k, z, m, pos, q, ans_v;
ll x1, p1, x2, p2;
vector<ll> g[300500], f;
ll orig_p[100500], dep[100500], p[100500];
void dfs(ll v, ll p = -1) {
    f.push_back(v);
    ll max_dep = 0;
    for (auto to : g[v]) {
        if (to == p) {
            continue;
        }
        dfs(to, v);
        max_dep = max(max_dep, dep[to] + 1);
    }
    dep[v] = max_dep;
}

bool cmp(ll x, ll y) {
    return dep[x] < dep[y];
}
vector<ll> ans;
int main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x;
        scanf("%d", &x);
        orig_p[i] = x;
        g[i].push_back(x);
        g[x].push_back(i);
    }
    orig_p[0] = 1;
    dfs(0);

    for (int i = 0; i < n; i++) {
        sort(g[i].begin(), g[i].end(), cmp);
    }
    f.clear();
    dfs(0);
    for (int v : f) {
        printf("%d ", v);
    }
    printf("\n");
    for (int i = 0; i < n-1; i++) {
        p[f[i+1]] = f[i];
    }

    for (int i = 1; i < n; i++) {
        while (p[f[i]] != orig_p[f[i]]) {
            ans.push_back(f[i]);
            p[f[i]] = p[p[f[i]]];
        }
    }
    cout << ans.size() << endl;
    for (int x : ans) {
        printf("%d ", x);
    }
    cout << endl;
    return 0;
}