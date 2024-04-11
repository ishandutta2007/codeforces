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

vector<int> slow(int n, int k, vector<int> a) {
    vector<int> res(1 << k, inf);
    for (int x = 0; x < (1 << k); x++) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res[x] = min(res[x], abs((a[i] ^ x) - (a[j] ^ x)));
            }
        }
    }
    return res;
}

// ans, min, max
tuple<vector<int>, vector<int>, vector<int>> rec(int k, vector<int> a) {
    int n = (int) a.size();
    int sz = 1 << k;
    if (k == 1) {
        vector<int> res(2, inf), mn(2, inf), mx(2, -inf);
        vector<int> aa = a;
        for (auto& x : aa) x &= 1;
        sort(aa.begin(), aa.end());
        for (int x = 0; x < 2; x++) {
            for (int i = 0; i < n; i++) {
                if (i + 1 < n)
                    res[x] = min(res[x], abs((aa[i] ^ x) - (aa[i + 1] ^ x)));
                mn[x] = min(mn[x], aa[i] ^ x);
                mx[x] = max(mx[x], aa[i] ^ x);
            }
        }
        return {res, mn, mx};
    }
    int sep = 0;
    while (sep < n && !((1 << (k - 1)) & a[sep])) sep++;
    if (sep == 0 || sep == n) {
        auto [res, mn, mx] = rec(k - 1, a);
        res.resize(sz);
        for (int i = 0; i < sz / 2; i++)
            res[i + sz / 2] = res[i];
        mn.resize(sz);
        mx.resize(sz);
        for (int x = sz / 2; x < sz; x++) {
            if (sep == 0) { // bit = 1
                mn[x] = mn[x - sz / 2];
                mx[x] = mx[x - sz / 2];
            } else { // bit = 0
                mn[x] = mn[x - sz / 2] + sz / 2;
                mx[x] = mx[x - sz / 2] + sz / 2;
            }
        }
        if (sep == 0) {
            for (int x = 0; x < sz / 2; x++)
                mn[x] += sz / 2, mx[x] += sz / 2;
        }
        return {res, mn, mx};
    }
    auto [res0, mn0, mx0] = rec(k - 1, vector<int>(a.begin(), a.begin() + sep));
    auto [res1, mn1, mx1] = rec(k - 1, vector<int>(a.begin() + sep, a.end()));
    vector<int> res(sz), mn(sz), mx(sz);
    for (int x = 0; x < sz / 2; x++)
        res[x] = min({res0[x], res1[x], mn1[x] + sz / 2 - mx0[x]});
    for (int x = sz / 2; x < sz; x++)
        res[x] = min({res0[x - sz / 2], res1[x - sz / 2], mn0[x - sz / 2] + sz / 2 - mx1[x - sz / 2]});
    for (int x = 0; x < sz / 2; x++) {
        mn[x] = min({mn0[x], mn1[x] + sz / 2});
        mx[x] = max({mx0[x], mx1[x] + sz / 2});
    }
    for (int x = sz / 2; x < sz; x++) {
        mn[x] = min({mn0[x - sz / 2] + sz / 2, mn1[x - sz / 2]});
        mx[x] = max({mx0[x - sz / 2] + sz / 2, mx1[x - sz / 2]});
    }
    return {res, mn, mx};
}

vector<int> fast(int n, int k, vector<int> a) {
    sort(a.begin(), a.end());
    return get<0>(rec(k, a));
}

void work() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> res = fast(n, k, a);
    for (auto x : res)
        cout << x << " ";
    cout << "\n";
}

void test() {
    mt19937 rnd(42);
    const int MAXK = 8;
    const int MAXN = 5;
    while (1) {
        int k = rnd() % MAXK + 1;
//        int n = rnd() % ((1 << k) - 1) + 2;
        int n = rnd() % MAXN + 2;
        vector<int> a(1 << k);
        iota(a.begin(), a.end(), 0);
        shuffle(a.begin(), a.end(), rnd);
        a.resize(n);
        vector<int> fs = fast(n, k, a);
        vector<int> sl = slow(n, k, a);
        if (fs == sl) {
            cout << "OK( "; for (auto x : fs) cout << x << " "; cout << ")" << endl;
        } else {
            cout << "WA\n";
            cout << "exp = "; for (auto x : sl) cout << x << " "; cout << "\n";
            cout << "fnd = "; for (auto x : fs) cout << x << " "; cout << "\n";
            cout << n << " " << k << "\n";
            for (int i = 0; i < n; i++)
                cout << a[i] << " ";
            cout << "\n";
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