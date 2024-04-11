#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
set < int > adj[maxN];
int p[maxN];
int n;
set < pair < int, int > > byClr[maxN];
int m;
int c, q;
int get(int a) {
    if (a == p[a]) return a;
    p[a] = get(p[a]);
    return p[a];
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (adj[a].size() < adj[b].size()) swap(a, b);
    for (int v : adj[b]) adj[a].insert(v);
    adj[b].clear();
    p[b] = a;
}
void add(int a, int b, int clr) {
    adj[get(a)].insert(b);
    auto it = byClr[b].lower_bound(make_pair(clr, -1));
    if (it == byClr[b].end() || (it -> first != clr)) {
        byClr[b].insert(make_pair(clr, a));
    }
    else {
        unite(a, (it -> second));
        //cout << a << " " << (it -> second) << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> c >> q;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int a, b, cc;
        cin >> a >> b >> cc;
        add(a, b, cc);
        add(b, a, cc);
    }
    for (int i = 1; i <= q; i++) {
        char tp;
        cin >> tp;
        if (tp == '+') {
            int x, y, z;
            cin >> x >> y >> z;
            add(x, y, z);
            add(y, x, z);
        }
        else {
            int x, y;
            cin >> x >> y;
            if (get(x) == get(y)) {
                cout << "Yes" << '\n';
            }
            else if (adj[get(x)].find(y) != adj[get(x)].end()) {
                cout << "Yes" << '\n';
            }
            else {
                cout << "No" << '\n';
            }
        }
    }
    return 0;
}