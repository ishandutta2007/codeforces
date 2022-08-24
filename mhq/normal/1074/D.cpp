#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 2 * (int)1e5 + 10;
pair < int, int > par[3 * maxN];
int val[3 * maxN];
int sz[3 * maxN];
map < int, int > mp;
pair < int, int > find_set(int x) {
    if (par[x].first != x) {
        int len = par[x].second;
        par[x] = find_set(par[x].first);
        par[x].second ^= len;
    }
    return par[x];
}
int ask(int l, int r) {
    if (!mp.count(l) || !mp.count(r)) return -1;
    int ind1 = mp[l];
    int ind2 = mp[r];
    auto t1 = find_set(ind1);
    auto t2 = find_set(ind2);
    if (t1.first != t2.first) return -1;
    return t1.second ^ t2.second;
}
int all_sz = 1;
int make_node(int x) {
    mp[x] = all_sz;
    par[all_sz] = make_pair(all_sz, 0);
    sz[all_sz] = 1;
    all_sz++;
    return all_sz - 1;
}
void go(int l, int r, int x) {
    int ind1 = -1;
    int ind2 = -1;
    if (!mp.count(l)) {
        ind1 = make_node(l);
    }
    else {
        ind1 = mp[l];
    }
    if (!mp.count(r)) {
        ind2 = make_node(r);
    }
    else {
        ind2 = mp[r];
    }
    if (sz[ind1] > sz[ind2]) swap(ind1, ind2);
    auto par1 = find_set(ind1);
    auto par2 = find_set(ind2);
    if (par1.first == par2.first) return ;
    par[par1.first] = make_pair(par2.first, par1.second ^ par2.second ^ x);
    sz[par2.first] += sz[par1.first];
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    srand(time(0));
    cin.tie(nullptr);
    int q;
    int last = 0;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        ///////
        //last = 0;
        int t;
        cin >> t;
        if (t == 1) {
            int l1, r1, x1;
            cin >> l1 >> r1 >> x1;
            int l = l1 ^ last;
            int r = r1 ^ last;
            int x = x1 ^ last;
            if (l > r) swap(l, r);
            go(l - 1, r, x);
        }
        else {
            int l2, r2;
            cin >> l2 >> r2;
            l2 ^= last;
            r2 ^= last;
            if (l2 > r2) swap(l2, r2);
            int ans = ask(l2 - 1, r2);
            cout << ans << '\n';
            if (ans == -1) ans = 1;
            last = ans;
        }
    }
    return 0;
}