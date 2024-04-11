
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// number of unique sides
// be careful about parallel lines that are negative vectors of each other
// compress by the vector of side lengths when ordering in clockwise order
// query number of distinct values in range
// Mo's algorithm

const int N = 1e5 + 5, M = 3e5 + 5, K = 550;
int n, k[N], L[N], val[M], q, ans[N], cnt[M];
vi x[N], y[N];
vector<pii> ve, p[N];

struct query {
    int l, r, ind;
    bool operator<(const query &o) const {
        if(l / K == o.l / K) {
            return r < o.r;
        }
        return l < o.l;
    }
} qu[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        L[i] = L[i - 1] + k[i - 1];
        cin >> k[i];
        x[i].assign(k[i], 0);
        y[i].assign(k[i], 0);
        p[i].assign(k[i], {0, 0});
        rep(j, 0, k[i]) {
            cin >> x[i][j] >> y[i][j];
        }
        rep(j, 0, k[i]) {
            int j2 = (j + 1) % k[i];
            int dx = x[i][j2] - x[i][j];
            int dy = y[i][j2] - y[i][j];
            int g = gcd(abs(dx), abs(dy));
            p[i][j] = {dx / g, dy / g};
            ve.push_back(p[i][j]);
        }
    }
    sort(all(ve));
    ve.erase(unique(all(ve)), ve.end());
    rep(i, 1, n + 1) {
        rep(j, 0, k[i]) {
            val[L[i] + j] = lower_bound(all(ve), p[i][j]) - ve.begin();
        }
    }
    cin >> q;
    rep(i, 0, q) {
        int l2, r2;
        cin >> l2 >> r2;
        qu[i].l = L[l2];
        qu[i].r = L[r2] + k[r2];
        qu[i].ind = i;
    }
    sort(qu, qu + q);
    int l = 0, r = 0, num = 0;
    auto ins = [&](int e) {
        num += (cnt[e] == 0);
        cnt[e]++;
    };
    auto del = [&](int e) {
        cnt[e]--;
        num -= (cnt[e] == 0);
    };
    rep(i, 0, q) {
        while(l > qu[i].l) ins(val[--l]);
        while(r < qu[i].r) ins(val[r++]);
        while(l < qu[i].l) del(val[l++]);
        while(r > qu[i].r) del(val[--r]);
        ans[qu[i].ind] = num;
    }
    rep(i, 0, q) {
        cout << ans[i] << '\n';
    }
}