
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

struct node {
    int x;
    node *le = NULL, *ri = NULL;
    node(int x = 0) : x(x) {}
    node* left() {
        return le = le ?: new node;
    }
    node* right() {
        return ri = ri ?: new node;
    }
};

struct tree {
    node *root;
    tree() {
        root = new node;
    }
    void add(node *i, int l, int r, int k, int x) {
        if(l == r) {
            i->x = max(i->x, x);
            return;
        }
        int m = (l + r) / 2;
        if(k <= m) add(i->left(), l, m, k, x);
        else add(i->right(), m + 1, r, k, x);
        i->x = max(i->left()->x, i->right()->x);
    }
    void add(int k, int x) {
        add(root, 0, 1e9 + 5, k, x);
    }
    int query(node *i, int l, int r, int L, int R) {
        if(r < L || R < l) return 0;
        if(L <= l && r <= R) return i->x;
        int m = (l + r) / 2;
        return max(query(i->left(), l, m, L, R), query(i->right(), m + 1, r, L, R));
    }
    int query(int L, int R) {
        return query(root, 0, 1e9 + 5, L, R);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vi kms;
    vi h(n + 1);
    rep(i, 1, n + 1) {
        cin >> h[i];
        kms.push_back(h[i]);
    }
    vector<vector<pii>> qu(n + 1);
    rep(i, 0, m) {
        int a, b;
        cin >> a >> b;
        qu[a].push_back({b, i});
        kms.push_back(b);
    }
    sort(all(kms));
    kms.erase(unique(all(kms)), kms.end());
    auto get = [&](int x) {
        return lower_bound(all(kms), x) - kms.begin() + 1;
    };
    rep(i, 1, n + 1) {
        h[i] = get(h[i]);
    }
    rep(i, 1, n + 1) {
        for(auto &pa : qu[i]) {
            pa.first = get(pa.first);
        }
    }

    vi ans(m, 1), L(n + 1, 0), R(n + 1, 0), cnt(n + 1, 0);
    tree T1, T2;
    rep(i, 1, n + 1) {
        for(auto &pa : qu[i]) {
            int b, q;
            tie(b, q) = pa;
            ans[q] += T1.query(1, b - 1);
        }
        L[i] = 1 + T1.query(1, h[i] - 1);
        T1.add(h[i], L[i]);
    }
    for(int i = n; i >= 1; i--) {
        for(auto &pa : qu[i]) {
            int b, q;
            tie(b, q) = pa;
            ans[q] += T2.query(b + 1, 1e9 + 5);
        }
        R[i] = 1 + T2.query(h[i] + 1, 1e9 + 5);
        T2.add(h[i], R[i]);
    }
    int LIS = T1.query(0, 1e9 + 5);
    rep(i, 1, n + 1) {
        if(L[i] + R[i] - 1 == LIS) cnt[L[i]]++;
    }
    rep(i, 1, n + 1) {
        int mx = LIS - 1;
        if(L[i] + R[i] - 1 == LIS) {
            if(cnt[L[i]] > 1) {
                mx = LIS;
            }
        }else {
            mx = LIS;
        }
        for(auto &pa : qu[i]) {
            int b, q;
            tie(b, q) = pa;
            ans[q] = max(ans[q], mx);
        }
    }
    rep(i, 0, m) {
        cout << ans[i] << '\n';
    }
}