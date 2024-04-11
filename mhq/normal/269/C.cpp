#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#define int long long
int n, m;
const int maxN = 2e5 + 10;
vector < pair < int, int > > g[maxN];
int tot[maxN];
bool used[maxN];
int pushed[maxN];
map < pair < int, int >, int > id;
int x[maxN], y[maxN];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x[i] = a;
        y[i] = b;
        tot[a] += c;
        tot[b] += c;
        if (a == n) {
//            pushed[b] += c;
            continue;
        }
        else if (b == n) {
            id[make_pair(a, b)] = 1;
//            pushed[a] += c;
            continue;
        }
        g[a].emplace_back(b, c);
        g[b].emplace_back(a, c);
    }
    for (int i = 1; i <= n; i++) tot[i] /= 2;
    queue < int > q;
//    for (int i = 2; i < n; i++) {
//        if (pushed[i] == tot[i]) {
//            q.push(i);
//            used[i] = true;
//        }
//    }
    q.push(1);
    used[1] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto& it : g[v]) {
            if (!used[it.first]) {
                pushed[it.first] += it.second;
                id[make_pair(v, it.first)] = 1;
                if (pushed[it.first] == tot[it.first]) {
                    used[it.first] = true;
                    q.push(it.first);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if (id.find(make_pair(x[i], y[i])) != id.end()) cout << 0 << '\n';
        else cout << 1 << '\n';
    }

    return 0;
}