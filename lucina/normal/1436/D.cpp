#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
vector <int> g[nax];
int64_t a[nax];
int n;
bool ok = false;
int64_t has = 0;
const int64_t lim = 1e15;
int64_t dfs(int node, int64_t x) {

    if (g[node].empty()) {
        if (a[node] > x) ok = false;
        return x - a[node];
    }
    int64_t cur = a[node];
    int64_t sum = 0;

    for (int to : g[node]) {
        sum += dfs(to, x);
        sum = min(sum, lim);
    }
    sum -= cur;
    if (sum < 0) ok = false;
    return sum;
}

bool check(int64_t x) {
    ok = true;
    dfs(1, x);
    return ok;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n;

    for (int i = 2 ; i <= n ; ++ i) {
        int p;
        cin >> p;
        g[p].push_back(i);
    }

    for (int i = 1 ; i <= n; ++ i) {
        cin >> a[i];
    }

    int64_t l = 0, r = 1e15, ans;

    while (l <= r) {
        int64_t mid = l + r >> 1;
        if (check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << '\n';
}