#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5 * (int)1e5 + 100;
int p[maxN];
int sz[maxN];
int get(int a) {
    if (a == p[a]) return a;
    p[a] = get(p[a]);
    return p[a];
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    sz[b] += sz[a];
    p[a] = b;
    return ;
}
vector < int > sp = {4, 8, 15, 16, 23, 42};
bool used[15];
int who[15];
map < int, pair < int, int > > mp;
int ans[10];
map < int, bool > all;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    for (int v : sp) {
        all[v] = true;
        for (int g : sp) {
            if (v < g) {
                mp[v * g] = make_pair(v, g);
            }
        }
    }
    for (int i = 1; i <= 4; i++) {
        cout << "? " << i << " " << i + 1 << endl;
        cin >> ans[i];
        // 0, 1, 2
    }
    for (int v : {mp[ans[1]].first, mp[ans[1]].second}) {
        map < int, bool > ws;
        for (int u : sp) ws[u] = true;
        bool all_ok = true;
        vector < int > tt;
        tt.push_back(v);
        ws[v] = false;
        for (int i = 1; i <= 4; i++) {
            if (ans[i] % tt.back() != 0) {
                all_ok = false;
                break;
            }
            tt.push_back(ans[i] / tt.back());
            if (!ws.count(tt.back()) || ws[tt.back()] == false) {
                all_ok = false;
                break;
            }
            ws[tt.back()] = false;
        }
        if (!all_ok) continue;
        for (auto t : ws) {
            if (t.second) {
                tt.push_back(t.first);
                break;
            }
        }
        cout << "! "; for (int u : tt) cout << u << " ";
        cout << endl;
        return 0;
    }
    assert(false);
    return 0;
}