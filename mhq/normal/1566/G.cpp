#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const ll INF = 5e9;
struct Fenw{
    vector<int> w;
    vector<int> f;
    int n;
    int cnt = 0;
    Fenw() {
        n = 0;
        f = {0};
        cnt = 0;
        w = {};
    }
    Fenw(vector<int> t) {
        w = t;
        sort(w.begin(), w.end());
        w.erase(unique(w.begin(), w.end()), w.end());
        n = w.size();
        f = vector<int>(n + 1);
    }
    void upd(int W, int by) {
        cnt += by;
        int pos = lower_bound(w.begin(), w.end(), W) - w.begin();
        assert(w[pos] == W);
        pos++;
        while (pos <= n) {
            f[pos] += by;
            pos = (pos | (pos - 1)) + 1;
        }
    }
    int get(int W) {
        int pos = upper_bound(w.begin(), w.end(), W) - w.begin();
        int ans = 0;
        while (pos > 0) {
            ans += f[pos];
            pos &= (pos - 1);
        }
        return ans;
    }
    int my_lower_bound(int lim) {
        int lg = 21;
        int res = 0;
        for (int k = lg; k >= 0; k--) {
            int p = (res + (1 << k));
            if (p <= n && f[p] < lim) {
                lim -= f[p];
                res += (1 << k);
            }
        }
        return res + 1;
    }
    ll calc_three() {
        if (cnt < 3) {
            return INF;
        }
        ll ans = 0;
        for (int z = 1; z <= 3; z++) {
            int where = my_lower_bound(z);
            ans += w[where - 1];
        }
        return ans;
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    Fenw all;
    vector<vector<int>> byW(n + 1);
    multiset<int> three;
    vector<int> weights;
    vector<pair<pair<int,int>, int>> cur;
    map<pair<int,int>,int> mp;
    for (int i = 1; i <= m; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        weights.emplace_back(w);
        byW[u].emplace_back(w);
        byW[v].emplace_back(w);
        cur.emplace_back(make_pair(u, v), w);
        mp[minmax(u, v)] = w;
    }
    int q;
    cin >> q;
    vector<int> tp(q), v(q), u(q), w(q);
    for (int i = 0; i < q; i++) {
        cin >> tp[i] >> v[i] >> u[i];
        if (tp[i] == 1) {
            cin >> w[i];
            mp[minmax(u[i], v[i])] = w[i];
            weights.emplace_back(w[i]);
            byW[u[i]].emplace_back(w[i]);
            byW[v[i]].emplace_back(w[i]);
        }
        else {
            w[i] = mp[minmax(u[i], v[i])];
        }
    }
    vector<Fenw> single(n + 1);
    all = Fenw(weights);
    for (int i = 1; i <= n; i++) {
        single[i] = Fenw(byW[i]);
    }
    set<pair<int,pair<int,int>>> ss;
    vector<ll> cur_three(n + 1, INF);
    multiset<ll> all_three;
    mp.clear();
    for (int i = 1; i <= n; i++) {
        all_three.insert(INF);
    }
    auto add_edge = [&](int x, int y, int w) {
        if (x > y) swap(x, y);
        mp[{x, y}] = w;
        all.upd(w, +1);
        single[x].upd(w, +1);
        single[y].upd(w, +1);
        ss.insert(make_pair(w, make_pair(x, y)));
        ll now = single[x].calc_three();
        if (now != cur_three[x]) {
            all_three.erase(all_three.find(cur_three[x]));
            cur_three[x] = now;
            all_three.insert(now);
        }
        now = single[y].calc_three();
        if (now != cur_three[y]) {
            all_three.erase(all_three.find(cur_three[y]));
            cur_three[y] = now;
            all_three.insert(now);
        }
    };
    auto del_edge = [&](int x, int y, int w) {
//        cout << " HI " << x << " " << y << " " << w << endl;
        if (x > y) swap(x, y);
        mp.erase(mp.find({x, y}));
        all.upd(w, -1);
        single[x].upd(w, -1);
        single[y].upd(w, -1);
        ss.erase(make_pair(w, make_pair(x, y)));
        ll now = single[x].calc_three();
        if (now != cur_three[x]) {
            all_three.erase(all_three.find(cur_three[x]));
            cur_three[x] = now;
            all_three.insert(now);
        }
        now = single[y].calc_three();
        if (now != cur_three[y]) {
            all_three.erase(all_three.find(cur_three[y]));
            cur_three[y] = now;
            all_three.insert(now);
        }
    };
    auto solve = [&](int x, int y, int W) {
        int l = -1;
        int r = all.w.size();
        while (r - l > 1) {
            int mid = (l + r) / 2;
            int weight = all.w[mid];
            int tot = all.get(weight);
            int c1 = single[x].get(weight);
            int c2 = single[y].get(weight);
            if (tot - c1 - c2 + (W <= weight)) r = mid;
            else l = mid;
        }
        if (r == all.w.size()) return INF;
        return (ll)all.w[r];
    };
    auto calc_ans = [&]() -> ll{
        assert(ss.size() >= 4);
        auto it1 = ss.begin();
        auto t1 = it1->second;
        int w1 = it1->first;
        it1++;
        auto t2 = it1->second;
        int w2 = it1->first;
        int a = -1;
        if (t1.first == t2.first || t1.first == t2.second) a = t1.first;
        if (t1.second == t2.first || t1.second == t2.second) a = t1.second;

        if (a == -1) return (ll)(w1 + w2);
        int b = (t1.first ^ t1.second) ^ a;
        int c = (t2.first ^ t2.second) ^ a;
        //optimize
        ll val1 = *(all_three.begin());
        val1 = min(val1, solve(a, b, w1) + w1);
        val1 = min(val1, solve(a, c, w2) + w2);
        if (mp.count(minmax(b, c))) {
            int d = mp[minmax(b, c)];
            val1 = min(val1, solve(b, c, d) + d);
        }
        return val1;
    };
    for (auto& it : cur) {
//        cout << " ADD " << it.first.first << " " << it.first.second << " " << it.second << endl;
        add_edge(it.first.first, it.first.second, it.second);
    }
    cout << calc_ans() << '\n';
    for (int i = 0; i < q; i++) {
        if (tp[i] == 0) {
            del_edge(u[i], v[i], w[i]);
        }
        else {
            add_edge(u[i], v[i], w[i]);
        }
        cout << calc_ans() << '\n';
    }
    return 0;
}