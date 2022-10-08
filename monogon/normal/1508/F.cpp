
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 25e3 + 5, K = 80;

struct query {
    int i, l, r;
};

bool cmp_mo(const query &a, const query &b) {
    if(a.l / K == b.l / K) return a.r < b.r;
    return a.l < b.l;
}

bool cmp_left(const query &a, const query &b) {
    return a.l < b.l;
}

int tree[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = INT_MAX;
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
int get(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return INT_MAX;
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return min(get(2 * i + 1, l, m, L, R), get(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int k, int x) {
    if(l == r) {
        tree[i] = min(tree[i], x);
        return;
    }
    int m = (l + r) / 2;
    if(k <= m) upd(2 * i + 1, l, m, k, x);
    else upd(2 * i + 2, m + 1, r, k, x);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vi a(n + 1), ainv(n + 1), ans(q + 1);
    vector<query> qu(q);
    rep(i, 1, n + 1) {
        cin >> a[i];
        ainv[a[i]] = i;
    }
    rep(i, 0, q) {
        cin >> qu[i].l >> qu[i].r;
        qu[i].i = i;
    }
    sort(all(qu), cmp_mo);
    set<int> se;
    vector<pii> e;
    vector<vi> lu(n + 1), ru(n + 1), ld(n + 1), rd(n + 1);
    vi plu(n + 1), pru(n + 1), pld(n + 1), prd(n + 1);

    auto edge = [&](int i, int j) {
        if(i > j) swap(i, j);
        e.push_back({i, j});
    };
    auto add = [&](int idx) {
        auto it = se.lower_bound(a[idx]);
        if(it != se.end()) edge(idx, ainv[*it]);
        if(it != se.begin()) edge(ainv[*prev(it)], idx);
        se.insert(it, a[idx]);
    };
    auto del = [&](int idx) {
        se.erase(a[idx]);
    };

    int L = min(K - 1, n), r = L;
    for(auto &x : qu) {
        while(L < x.l) {
            L = min(n, L + K);
            se.clear();
            r = L;
        }
        if(x.r <= L) {
            se.clear();
            rep(i, x.l, x.r + 1) add(i);
            se.clear();
        }else {
            while(r < x.r) add(++r);
            for(int i = L; i >= x.l; i--) add(i);
            rep(i, x.l, L + 1) del(i);
        }
    }
    sort(all(qu), cmp_left);
    sort(all(e));
    e.erase(unique(all(e)), e.end());
    auto qit = qu.begin();
    auto eit = e.begin();
    build(0, 1, n);
    vector<vector<pii>> ev(q + 1);
    while(qit != qu.end() || eit != e.end()) {
        if(qit == qu.end() || (eit != e.end() && eit->first < qit->l)) {
            ev[min(q, get(0, 1, n, eit->second, n))].push_back(*eit);
            eit++;
        }else {
            upd(0, 1, n, qit->r, qit->i);
            qit++;
        }
    }

    unordered_set<int> ed;
    auto addedge = [&](int i, int j) {
        ed.insert(i * N + j);
    };
    auto findedge = [&](int i, int j) {
        return ed.find(i * N + j) != ed.end();
    };
    auto deledge = [&](int i, int j) {
        ed.erase(i * N + j);
    };

    int cnt = 0;
    auto good = [&](int i, int j) {
        if(a[i] < a[j]) {
            return pru[i] < sz(ru[i]) && pld[j] < sz(ld[j]) && ru[i][pru[i]] == j && ld[j][pld[j]] == i;
        }else {
            return prd[i] < sz(rd[i]) && plu[j] < sz(lu[j]) && rd[i][prd[i]] == j && lu[j][plu[j]] == i;
        }
    };

    for(auto &pa : e) {
        int i, j;
        tie(i, j) = pa;
        addedge(i, j);
        if(a[i] < a[j]) {
            ru[i].push_back(j);
            ld[j].push_back(i);
        }else {
            rd[i].push_back(j);
            lu[j].push_back(i);
        }
    }

    rep(i, 1, n + 1) {
        sort(all(lu[i]));
        sort(all(ru[i]), greater<>());
        sort(all(ld[i]));
        sort(all(rd[i]), greater<>());
    }

    for(auto &pa : e) {
        if(good(pa.first, pa.second)) {
            cnt++;
        }
    }

    bool fi, fj;
    for(int ti = q - 1; ti >= 0; ti--) {
        for(auto &pa : ev[ti + 1]) {
            int i, j;
            tie(i, j) = pa;
            if(good(i, j)) {
                cnt--;
            }
            deledge(i, j);
            fi = false, fj = false;
            if(a[i] < a[j]) {
                while(pru[i] < sz(ru[i]) && !findedge(i, ru[i][pru[i]])) pru[i]++, fi = true;
                while(pld[j] < sz(ld[j]) && !findedge(ld[j][pld[j]], j)) pld[j]++, fj = true;
                if(fi && pru[i] < sz(ru[i]) && good(i, ru[i][pru[i]])) {
                    cnt++;
                }
                if(fj && pld[j] < sz(ld[j]) && good(ld[j][pld[j]], j)) {
                    cnt++;
                }
            }else {
                while(prd[i] < sz(rd[i]) && !findedge(i, rd[i][prd[i]])) prd[i]++, fi = true;
                while(plu[j] < sz(lu[j]) && !findedge(lu[j][plu[j]], j)) plu[j]++, fj = true;
                if(fi && prd[i] < sz(rd[i]) && good(i, rd[i][prd[i]])) {
                    cnt++;
                }
                if(fj && plu[j] < sz(lu[j]) && good(lu[j][plu[j]], j)) {
                    cnt++;
                }
            }
        }
        ans[ti] = cnt;
    }

    rep(i, 0, q) cout << ans[i] << '\n';
}