#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e5 + 10;
int a[maxN];
int n;
int p[maxN];
int cnt[maxN];
int par[maxN];
vector<int> who[maxN];
int sz[maxN];
int get(int x) {
    if (x == par[x]) {
        return x;
    }
    return par[x] = get(par[x]);
}
void unite(int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
}
void solve() {
    cin >> n;
//    n = rand()  % 5 + 2;
//    cout << n << endl;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
//        a[i] = rand() % n + 1;
//        cout << a[i] << " ";
        cnt[i] = 0;
        par[i] = i;
        sz[i] = 1;
        who[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
        who[a[i]].emplace_back(i);
    }
    int num = -1;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] % 2 == 1) {
            if (num != -1) {
                cout << "NO\n";
                return ;
            }
            num = i;
        }
    }
    if (num != -1) {
        assert(n % 2 == 1);
        int pos = (n + 1) / 2;
        if (who[num].size() == 1 && a[pos] == num) {
            cout << "NO\n";
            return;
        }
        if (who[num].back() != pos) {
        }
        else {
            swap(who[num][who[num].size() - 2], who[num].back());
        }
        assert(who[num].back() != pos);
        p[pos] = who[num].back();
        unite(pos, p[pos]);
        who[num].pop_back();
    }
    cout << "YES\n";
    vector<pair<int,int>> pairs;
    for (int i = 1; i <= n; i++) {
        for (int z = 0; z < who[i].size(); z += 2) {
            pairs.emplace_back(who[i][z], who[i][z + 1]);
        }
    }
    for (int i = 1; i < n + 1 - i; i++) {
        int l = i;
        int r = n + 1 - i;
        assert(get(l) != get(r));
        if (pairs.size() == 1) {
            int c1 = pairs[0].first;
            int c2 = pairs[0].second;
            if (get(l) == get(c1)) {
                swap(c1, c2);
            }
            assert(get(l) == get(c2) && get(r) == get(c1));
            p[l] = c1;
            p[r] = c2;
            unite(l, c1);
            unite(r, c2);
//            cout << " hi " << l << " " << r << endl;
            pairs.pop_back();
        }
        else {
            auto it = pairs.back();
            int c1 = it.first;
            int c2 = it.second;
            if (get(l) == get(c1) || get(r) == get(c2)) {
                swap(c1, c2);
            }
            if ((get(l) == get(c1) || get(r) == get(c2)) || (get(l) == get(c2) && get(r) == get(c1))) {
                swap(pairs[pairs.size() - 2], pairs.back());
                auto it = pairs.back();
                int c1 = it.first;
                int c2 = it.second;
                if (get(l) == get(c1) || get(r) == get(c2)) {
                    swap(c1, c2);
                }
                assert(get(l) != get(c1) && get(r) != get(c2));
                unite(l, c1);
                unite(r, c2);
                p[l] = c1;
                p[r] = c2;
            }
            else {
                unite(l, c1);
                unite(r, c2);
                p[l] = c1;
                p[r] = c2;
            }
            pairs.pop_back();
        }
    }
    int sz_cyc = 0;
    int c = p[1];
    for (int i = 1; i <= n; i++) {
        if (c == 1) {
            sz_cyc = i;
            break;
        }
        c = p[c];
    }

    for (int i = 1; i <= n; i++) cout << p[i] << " ";
//    cout << endl;
    assert(sz_cyc == n);
    for (int i = 1; i <= n + 1 - i; i++) {
        assert(a[p[i]] == a[p[n + 1 - i]]);
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst = 1488;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}