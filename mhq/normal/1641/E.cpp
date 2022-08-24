#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = 998244353;

const int root = 646;

const int root_1 = 208611436;

const int root_pw = 1<<20;

int mult(int a, int b) {
    return (1LL * a * b) % mod;
}

int pw(int a, int b) {
    if (b == 0) return 1;
    if (b & 1) return mult(a, pw(a, b - 1));
    int res = pw(a, b / 2);
    return mult(res, res);
}

int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}

int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}

void fft (vector<int> & a, bool invert) {
    int n = (int) a.size();

    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }

    for (int len=2; len<=n; len<<=1) {
        int wlen = invert ? root_1 : root;
        for (int i=len; i<root_pw; i<<=1)
            wlen = int (wlen * 1ll * wlen % mod);
        for (int i=0; i<n; i+=len) {
            int w = 1;
            for (int j=0; j<len/2; ++j) {
                int u = a[i+j],  v = int (a[i+j+len/2] * 1ll * w % mod);
                a[i+j] = u+v < mod ? u+v : u+v-mod;
                a[i+j+len/2] = u-v >= 0 ? u-v : u-v+mod;
                w = int (w * 1ll * wlen % mod);
            }
        }
    }
    if (invert) {
        int nrev = pw(n, mod - 2);
        for (int i=0; i<n; ++i)
            a[i] = int (a[i] * 1ll * nrev % mod);
    }
}

vector<int> poly_mult(vector < int > a, vector < int > b) {
    int s = a.size() + b.size();
    int r = 1;
    while (r < s) r *= 2;
    a.resize(r);
    b.resize(r);
    fft(a, false);
    fft(b, false);
    for (int j = 0; j < r; j++) {
        a[j] = mult(a[j], b[j]);
    }
    fft(a, true);
    return a;
//    while (!a.empty() && (a.back() == 0)) a.pop_back();
}
int n, m;
const int maxN = 1e5 + 10;
int a[maxN];
bool can[maxN];
int pw2[maxN];
int pref[maxN];
int ans = 0;
int F[maxN];
int S[maxN];
void go(int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    go(l, mid);
    go(mid + 1, r);
    vector<int> l1(mid - l + 1);
    vector<int> l2(mid - l + 1);
    vector<int> r1(r - mid);
    vector<int> r2(r - mid);
    int cnt_right = sub(pw2[pref[r] - pref[mid]], 1);
    int cnt_left = sub(pw2[pref[mid] - pref[l - 1]], 1);
    if (!cnt_right || !cnt_left) return;

//    cout << l << " " << mid << " " << r << " " << pref[n] << endl;
    int coef = pw2[pref[n] - (pref[r] - pref[l - 1])];
    for (int i = l; i <= mid; i++) {
        if (can[i] == 1) {
            int prob = pw2[pref[i - 1] - pref[l - 1]];
            l1[i - l] = prob;
            l2[i - l] = mult(i, prob);
            ans = sub(ans, mult(mult(mult(coef, prob), cnt_right), F[i - 1]));
            ans = sum(ans, mult(i, mult(mult(mult(coef, prob), cnt_right), S[i - 1])));
        }
    }
    for (int i = mid + 1; i <= r; i++) {
        if (can[i] == 1) {
            int prob = pw2[pref[r] - pref[i]];
            r1[i - mid - 1] = prob;
            r2[i - mid - 1] = mult(i, prob);
            ans = sub(ans, mult(mult(mult(coef, prob), cnt_left), F[i]));
            ans = sum(ans, mult(i, mult(mult(mult(coef, prob), cnt_left), S[i])));
        }
    }
    auto f1 = poly_mult(l1, r1);
    for (int z = 0; z < f1.size(); z++) {
        int k = (mid + 1 + l + z) / 2;
        if (!f1[z]) continue;
        ans = sum(ans, mult(coef, mult(F[k], f1[z])));
        ans = sum(ans, mult(coef, mult(F[k], f1[z])));
    }
    auto f2 = poly_mult(l2, r1);
    for (int z = 0; z < f2.size(); z++) {
        int k = (mid + 1 + l + z) / 2;
        if (!f2[z]) continue;
        ans = sub(ans, mult(coef, mult(S[k], f2[z])));
    }
    auto f3 = poly_mult(r2, l1);
    for (int z = 0; z < f3.size(); z++) {
        int k = (mid + 1 + l + z) / 2;
        if (!f3[z]) continue;
        ans = sub(ans, mult(coef, mult(S[k], f3[z])));
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    pw2[0] = 1;
    for (int i = 1; i < maxN; i++) {
        pw2[i] = mult(pw2[i - 1], 2);
        assert(pw2[i] != 0);
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        S[i] = sum(S[i - 1], a[i]);
        F[i] = sum(F[i - 1], mult(a[i], i));
    }
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        can[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + can[i];
    }
    //add_pref add_suf
    int sum_a = 0;
    int sum_mult = 0;
    for (int i = 1; i <= n; i++) {
        sum_a = sum(sum_a, a[i]);
        sum_mult = sum(sum_mult, mult(a[i], i));
        if (can[i] == 1) {
            int ways = pw2[pref[n] - pref[i]];
            ans = sum(ans, mult(ways, sub(mult(i, sum_a), sum_mult)));
        }
    }
    sum_a = 0;
    sum_mult = 0;
    for (int i = n; i >= 1; i--) {
        sum_a = sum(sum_a, a[i]);
        sum_mult = sum(sum_mult, mult(a[i], i));
        if (can[i] == 1) {
            int ways = pw2[pref[i - 1]];
            ans = sum(ans, mult(ways, sub(sum_mult, mult(sum_a, i))));
        }
    }
    go(1, n);
    ans = mult(ans, pw(sub(pw2[m], 1), mod - 2));
    cout << ans << '\n';
    return 0;
}