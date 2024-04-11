#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2049;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
vector < int > p;
int Q = 0;
map < pair < int, int >, int > mp;
vector < int > f[maxN];
int ask(int x, int y) {
    if (mp.find(minmax(x, y)) != mp.end()) return mp[minmax(x, y)];
    cout << "? " << x + 1 << " " << y + 1 << endl;
    f[x].emplace_back(y);
    f[y].emplace_back(x);
    Q++;
#ifdef DEBUG
    int cc = (p[x] | p[y]);
    mp[minmax(x, y)] = cc;
    return cc;
#endif
    int c;
    cin >> c;
    return mp[minmax(x, y)] = c;
}
int n;
/*int solve(vector < int > all) {
    if (all.size() == 1) return all[0];
    if (all.size() <= 4) {
        vector < int > cands;
        for (int i = 0; i < all.size(); i++) {
            cands.emplace_back(all[i]);
        }
        while (cands.size() >= 2) {
            int x = cands[cands.size() - 2];
            int y = cands[cands.size() - 1];
            cands.pop_back();
            cands.pop_back();
        }
    }
    int n = all.size();
    int p = 0;
    while (n >= 1) {
        n /= 2;
        p++;
    }
    p /= 2;

}*/
int solve2(vector < int > all) {
    shuffle(all.begin(), all.end(), rnd);
    while (all.size() >= 2) {
        int x = all[all.size() - 1];
        int y = all[all.size() - 2];
        all.pop_back();
        all.pop_back();
        bool badX = false;
        bool badY = false;
        for (int v : f[x]) {
            if (v == y) continue;
            int d1 = ask(v, x);
            int d2 = ask(v, y);
            if (d1 != d2) {
                if ((d1 | d2) != d1) badY = true;
                if ((d1 | d2) != d2) badX = true;
                break;
            }
        }
        if (badX | badY) {
            if (!badX) all.emplace_back(x);
            if (!badY) all.emplace_back(y);
        }
        else {
            while (true) {
                int v = rnd() % n;
                while (v == x || v == y) v = rnd() % n;
                int d1 = ask(v, x);
                int d2 = ask(v, y);
                if (d1 != d2) {
                    if ((d1 | d2) != d1) badY = true;
                    if ((d1 | d2) != d2) badX = true;
                    break;
                }
            }
            if (!badX) all.emplace_back(x);
            if (!badY) all.emplace_back(y);
        }
    }
    return all[0];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
#ifdef DEBUG
    p.resize(n);
    iota(p.begin(), p.end(), 0);
    shuffle(p.begin(), p.end(), rnd);
#endif
    vector < int > all(n);
    iota(all.begin(), all.end(), 0);
    int ind = -1;
    while (true) {
        int x = rnd() % n;
        int y = rnd() % n;
        if (x == y) continue;
        if (__builtin_popcount(ask(x, y)) <= 6) {
            ind = x;
            break;
        }
    }
    vector < pair < int, int > > ggwp;
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
        if (i == ind) continue;
        ggwp.emplace_back(ask(i, ind), i);
        mn = min(mn, ask(i, ind));
    }
    vector < int > ff;
    for (auto& it : ggwp) {
        if (it.first == mn) ff.emplace_back(it.second);
    }
    ff.emplace_back(ind);
    int zero = solve2(ff);
//    cout << zero << " WUT " << endl;
    vector < int > ans(n);
    for (int i = 0; i < n; i++) {
        if (zero == i) {
            ans[zero] = 0;
            continue;
        }
        int pp = ask(zero, i);
        ans[i] = pp;
    }
    cout << "! ";
    for (int v : ans) cout << v << " ";
#ifdef DEBUG
    assert(ans == p);
#endif
    cout << Q << endl;
    return 0;
}