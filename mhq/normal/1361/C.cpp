#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (1 << 20) + 10;
int p[maxN];
int par[maxN];
bool has[maxN];
mt19937 rnd(228);
int tt[maxN];
int sz[maxN];
int dd[maxN];
int get(int a) {
    if (a == par[a]) return a;
    return par[a] = get(par[a]);
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}
bool can(int mid) {
    assert(mid >= 1);
    for (int i = 0; i < (1 << mid); i++) {
        par[i] = i;
        has[i] = false;
        dd[i] = 0;
        sz[i] = 1;
    }
    int CNT = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int val = p[i];
        val &= ((1 << mid) - 1);
        tt[i] = val;
        if (!has[val]) {
            has[val] = true;
            CNT++;
        }
    }
    for (int i = 1; i <= 2 * n; i += 2) {
        unite(tt[i], tt[i + 1]);
        if (tt[i] != tt[i + 1]) {
            dd[tt[i]]++;
            dd[tt[i + 1]]++;
        }
    }
    if (sz[get(tt[1])] != CNT) return false;
    for (int i = 0; i < (1 << mid); i++) {
        if (dd[i] % 2 == 1) return false;
    }
    return true;
}
vector < pair < int, int > > g[maxN];
bool was[maxN];
int ptr[maxN];
set < pair < int, int > > aue[maxN];
void go(int mid) {
    for (int i = 1; i <= 2 * n; i++) {
        int val = p[i];
        val &= ((1 << mid) - 1);
        tt[i] = val;
    }
    for (int i = 1; i <= 2 * n; i += 2) {
        if (tt[i] != tt[i + 1]) {
            g[tt[i]].emplace_back(tt[i + 1], (i + 1) / 2);
            g[tt[i + 1]].emplace_back(tt[i], (i + 1) / 2);
            aue[tt[i]].insert({tt[i + 1], (i + 1) / 2});
            aue[tt[i + 1]].insert({tt[i], (i + 1) / 2});
        }
        else {
            g[tt[i]].emplace_back(tt[i], (i + 1) / 2);
            aue[tt[i]].insert({tt[i], (i + 1) / 2});
        }
    }
    stack < int > st;
    vector < int > res;
    st.push(tt[1]);
    while (!st.empty()) {
        int v = st.top();
        bool fnd = false;
        while (ptr[v] < g[v].size()) {
            if (was[g[v][ptr[v]].second]) {
                ptr[v]++;
                continue;
            }
            else {
                fnd = true;
                was[g[v][ptr[v]].second] = true;
                st.push(g[v][ptr[v]].first);
                break;
            }
        }
        if (!fnd) {
            res.emplace_back(v);
            st.pop();
        }
    }
    cout << mid << '\n';
    for (int i = 0; i + 1 < res.size(); i++) {
        int p1 = res[i];
        int p2 = res[i + 1];
        auto it = aue[p1].lower_bound(make_pair(p2, -1));
        assert(it->first == p2);
        int id = it->second;
        aue[p1].erase(it);
        if (p2 != p1) {
            aue[p2].erase(make_pair(p1, id));
        }
        if (tt[2 * id - 1] == p1) {
            cout << 2 * id - 1 << " " << 2 * id << " ";
        }
        else {
            cout << 2 * id << " " << 2 * id - 1 << " ";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[2 * i - 1] >> p[2 * i];
    }
    int l = 0;
    int r = 21;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (can(mid)) l = mid;
        else r = mid;
    }
    go(l);
    return 0;
}