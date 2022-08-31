#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
string s;
const int maxN = 2e5 + 25;
int fenw[maxN];
int LIM;
void addSuf(int r, int by) {
    while (r <= LIM) {
        fenw[r] += by;
        r = (r | (r - 1)) + 1;
    }
}
void add(int l, int r, int by) {
    addSuf(l, by);
    addSuf(r + 1, -by);
}
int get(int l) {
    int ans = 0;
    while (l > 0) {
        ans += fenw[l];
        l &= (l - 1);
    }
    return ans;
}
char symb[maxN];
bool active[maxN];
int sz[maxN];
int f[26];
int tp[maxN];
vector < int > alive[26];
int prv_not[maxN];
int nxt_not[maxN];
int prv[maxN];
int nxt[maxN];
set < int > byId[26];
void solve() {
    int pp = rand() % 10 + 5;
    s.clear();
//    for (int i = 0; i < pp; i++) s += (char)(rand() % 3 + 'a');
    cin >> s;
//    cout << s << endl;
    LIM = s.size() + 2;
    int n = s.size();
    for (int i = 0; i <= n + 5; i++) fenw[i] = 0;
    for (int i = 0; i < n; i++) {
        symb[i + 1] = s[i];
    }
    int st = 1;
    vector < pair < pair < int, int >, char > > gr;
    for (int i = 2; i <= n; i++) {
        if (symb[i] != symb[st]) {
            if (st + 1 <= i - 1) {
                gr.emplace_back(make_pair(st, i - 1), symb[st]);
            }
            st = i;
        }
    }

    if (st < n) {
        gr.emplace_back(make_pair(st, n), symb[st]);
    }

    int sz_g = gr.size();
    memset(f, 0, sizeof f);
    for (int i = 0; i < 26; i++) {
        alive[i].clear();
    }
    int len = n;

    for (int i = 0; i < 26; i++) {
        byId[i].clear();
    }
    for (int i = 0; i < sz_g; i++) {
        sz[i + 1] = gr[i].first.second - gr[i].first.first + 1;
        tp[i + 1] = gr[i].second - 'a';
        f[tp[i + 1]] += sz[i + 1] - 1;
        active[i + 1] = true;
        add(i + 1, i + 1, gr[i].first.first);
        active[i + 1] = true;
        alive[tp[i + 1]].emplace_back(i + 1);
        byId[tp[i + 1]].insert(i + 1);
    }
    /*prv_not[1] = -1;
    prv[1] = -1;
    for (int i = 2; i <= sz_g; i++) {
        prv[i] = i - 1;
        if (tp[i] != tp[i - 1]) prv_not[i] = i - 1;
        else {
            prv_not[i] = prv_not[i - 1];
        }
    }

    nxt_not[sz_g] = -1;
    nxt[sz_g] = -1;
    for (int i = sz_g - 1; i >= 1; i--) {
        nxt[i] = i + 1;
        if (tp[i] != tp[i + 1]) nxt_not[i] = i + 1;
        else nxt_not[i] = nxt_not[i + 1];
    }
     */
    int real_ans = 0;
    int sm = 0;
    for (int i = 0; i < 26; i++) {
        real_ans = max(real_ans, f[i] + 1);
        sm += f[i];
    }
    real_ans = max(real_ans, (sm + 1) / 2 + 1);
    vector < pair < int, int > > ans;
    auto del = [&](int x) {
        active[x] = false;
        byId[tp[x]].erase(x);
        /*int p = prv[x];
        int q = nxt[x];
        if (p != -1) {
            nxt[p] = q;
        }
        if (q != -1) {
            prv[q] = p;
        }
        if (p != -1 && tp[p] != tp[x]) {
            if (q == -1) {
                nxt_not[p] = -1;
            }
            else if (tp[p] != tp[q]) {
                nxt_not[p] = q;
            }
            else {
                nxt_not[p] = nxt_not[q];
            }
        }
        if (q != -1 && tp[q] != tp[x]) {
            if (p == -1) {
                prv_not[q] = -1;
            }
            else if (tp[p] != tp[q]) {
                prv_not[q] = p;
            }
            else {
                prv_not[q] = prv_not[p];
            }
        }*/
    };

    auto add_to_ans = [&](int x, int y) {
        /*assert(x != -1 && y != -1);
        assert(nxt[x] == y && prv[y] == x);*/
        int x_r = get(x) + sz[x] -1 ;
        int y_l = get(y);
        ans.emplace_back(x_r, y_l);
        int len_to_del = y_l - x_r + 1;
        len -= len_to_del;
        addSuf(y, -len_to_del);
        add(y, y, +1);
        sz[x] -= 1;
        sz[y] -= 1;
        f[tp[x]] -= 1;
        f[tp[y]] -= 1;
        if (sz[x] == 1) del(x);
        if (sz[y] == 1) del(y);
    };

    auto getNext =[&](int x) {
        int mn = sz_g + 1;
        for (int i = 0; i < 26; i++) {
            if (i == tp[x]) continue;
            auto it = byId[i].lower_bound(x);
            if (it != byId[i].end()) mn = min(mn, *it);
        }
        if (mn > sz_g) return -1;
        return mn;
    };
    auto getPrev =[&](int x) {
        int mx = -1;
        for (int i = 0; i < 26; i++) {
            if (i == tp[x]) continue;
            auto it = byId[i].lower_bound(x);
            if (it != byId[i].begin()) mx = max(mx, *(--it));
        }
        return mx;
    };
    while (true) {
        pair < int, int > mx = make_pair(0, -1);
        int cur_sm = 0;
        for (int i = 0; i < 26; i++) {
            mx = max(mx, make_pair(f[i], i));
            cur_sm += f[i];
        }
        if (mx.first == 0) break;
        int symb = mx.second;
        while (!alive[symb].empty() && !active[alive[symb].back()]) {
            alive[symb].pop_back();
        }
        assert(!alive[symb].empty());
        int who_gr = alive[symb].back();
        if (cur_sm == mx.first) {
            // don't have any other
            int his_l = get(who_gr);
            ans.emplace_back(his_l, his_l);
            addSuf(who_gr + 1, -1);
            len -= 1;
            sz[who_gr] -= 1;
            f[tp[who_gr]] -= 1;
            if (sz[who_gr] == 1) {
                del(who_gr);
            }
        }
        else {
            int p = getNext(who_gr);
            if (p != -1) {
                int c = getPrev(p);
                assert(tp[c] == tp[who_gr]);
                add_to_ans(c, p);
            }
            else {
                p = getPrev(who_gr);
                int c = getNext(p);
                assert(tp[c] == tp[who_gr]);
                add_to_ans(p, c);
            }
        }
    }
    ans.emplace_back(1, len);
    assert(ans.size() == real_ans);
    cout << ans.size() << '\n';
    for (auto it : ans) {
        cout << it.first << " " << it.second << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst = 100000;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}