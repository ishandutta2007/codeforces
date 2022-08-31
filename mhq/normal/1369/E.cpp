#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
set < int > by[maxN];
int n, m;
int w[maxN];
bool used[maxN];
int c[maxN][2];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    vector < int > ans;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        c[i][0] = a;
        c[i][1] = b;
        by[a].insert(i);
        by[b].insert(i);
    }
    queue < int > q;
    for (int i = 1; i <= n; i++) {
        if (w[i] >= by[i].size()) {
            q.push(i);
            used[i] = true;
        }
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int p : by[v]) {
            ans.emplace_back(p);
        }
        for (int p : by[v]) {
            int other = (c[p][0] ^ c[p][1]) ^ v;
            by[other].erase(p);
            if (w[other] >= by[other].size() && !used[other]) {
                used[other] = true;
                q.push(other);
            }
        }
    }
    if (ans.size() != m) {
        cout << "DEAD";
        return 0;
    }
    cout << "ALIVE\n";
    reverse(ans.begin(), ans.end());
    for (int v : ans) cout << v << " ";
    return 0;
}