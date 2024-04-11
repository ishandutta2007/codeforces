#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

struct SQRT {
    int n = 0;
    int k = 0;
    vector<int> cnt;
    vector<int> f, F;

    SQRT(int nn) {
        n = nn;
        while (k * k <= n)
            k++;
        cnt.assign(n + 1, 0);
        f.assign(n + 1, 0);
        F.assign(n / k + 1, 0);
        for (int i = 1; i <= n; i++)
            upd_f(0, +1);
    }

    void upd_f(int c, int d) {
        f[c] += d;
        F[c / k] += d;
    }

    void upd(int x, int d) {
        upd_f(cnt[x], -1);
        cnt[x] += d;
        upd_f(cnt[x], +1);
    }

    int query() { // cnt[x], cnt[x] -> max
        int b = (int) F.size() - 1;
        while (F[b] == 0)
            b--;
        for (int x = b * k + k - 1; ; x--) {
            if (x <= n && f[x] > 0)
                return x;
        }
    }
};

vector<int> fast(int n, int q, vector<int> a, vector<pii> b) {
    vector<int> perm(q);
    for (int i = 0; i < q; i++)
        perm[i] = i;
    int k = 1; while (k * k < n) k++;
    auto get_mo_pair = [&](int i) -> pii {
        auto [l, r] = b[i];
        return {l / k, r};
    };
    sort(perm.begin(), perm.end(), [&](int i, int j) {
        return get_mo_pair(i) < get_mo_pair(j);
    });
    int ql = 1, qr = 0;
    SQRT sq(n);
    vector<int> res(q, inf);
    for (int qid : perm) {
        auto [l, r] = b[qid];
        while (qr < r) sq.upd(a[++qr], +1);
        while (ql > l) sq.upd(a[--ql], +1);
        while (qr > r) sq.upd(a[qr--], -1);
        while (ql < l) sq.upd(a[ql++], -1);
        int x = r - l + 1;
        int k = (x + 1) / 2;
        int A = sq.query();
        int B = x - A;
        if (A <= B + 1) {
            res[qid] = 1;
            continue;
        }
        res[qid] = min({
            1 + x - (2 * B + 1),
            2 * B >= A ? B : A - B
        });
    }
    return res;
}

vector<int> slow(int n, int q, vector<int> a, vector<pii> b) {
    auto calculate = [](vector<int> ar) -> int {
        int sz = (int) ar.size();
        vector<int> dp(1 << sz, inf);
        dp[0] = 0;
        for (int mask = 1; mask < (1 << sz); mask++) {
            for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
                unordered_map<int, int> cnt;
                int len = 0;
                for (int i = 0; i < sz; i++) {
                    if ((1 << i) & sub) {
                        cnt[ar[i]]++;
                        len++;
                    }
                }
                int mx = 0;
                for (auto item : cnt)
                    mx = max(mx, item.second);
                if (mx <= (len + 1) / 2)
                    dp[mask] = min(dp[mask], dp[mask ^ sub] + 1);
            }
        }
        return dp[(1 << sz) - 1];
    };
    vector<int> res(q, inf);
    for (int it = 0; it < q; it++) {
        auto [l, r] = b[it];
        res[it] = calculate({a.begin() + l, a.begin() + r + 1});
    }
    return res;
}

void work() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<pii> b(q);
    for (int i = 0; i < q; i++)
        cin >> b[i].first >> b[i].second;
    vector<int> fs = fast(n, q, a, b);
    for (auto x : fs)
        cout << x << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXN = 10;
    while (1) {
        int n = rnd() % MAXN + 1;
        int q = rnd() % MAXN * MAXN + 1;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
            a[i] = rnd() % min(n, 2) + 1;
        vector<pii> b(q);
        for (int i = 0; i < q; i++) {
            int r = rnd() % n + 1;
            int l = rnd() % r + 1;
            b[i] = {l, r};
        }
        auto fs = fast(n, q, a, b);
        auto sl = slow(n, q, a, b);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n\n";
            cout << n << " " << q << "\n";
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
            cout << "\n";
            for (auto [l, r] : b)
                cout << l << " " << r << "\n";
            break;
        }
    }
}

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    work();
//    test();

    return 0;
}