#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

using comp = complex<long double>;
const long double PI = acos(-1);
 
inline int reversed(int mask, int log) {
    int rev_mask = 0;
    for (int i = 0; i < log; i++)
        if ((mask >> i) & 1)
            rev_mask ^= 1 << (log - i - 1);
 
    return rev_mask;
}
 
void fft(vector<comp> &a) {
    int n = int(a.size());
    int log = __lg(n);
 
    for (int i = 0; i < n; i++)
        if (i > reversed(i, log))
            swap(a[i], a[reversed(i, log)]);
 
    for (int len = 1; len < n; len *= 2) {
        comp base(cos(PI / len), sin(PI / len));
        for (int i = 0; i < n; i += 2 * len) {
            comp w = 1;
            for (int j = i; j < i + len; j++) {
                comp left = a[j];
                comp right = a[j + len] * w;
                a[j] = left + right;
                a[j + len] = left - right;
                w *= base;
            }
        }
    }
}
 
vector<long long> multiply(vector<int> a, vector<int> b) {
    int p2 = 1;
    while (p2 < int(a.size() + b.size()))
        p2 *= 2;
 
    a.resize(p2);
    b.resize(p2);
 
    vector<comp> fa(a.begin(), a.end());
    vector<comp> fb(b.begin(), b.end());
 
    fft(fa);
    fft(fb);
    for (int i = 0; i < p2; i++)
        fa[i] *= fb[i];
 
    fft(fa);
    reverse(fa.begin() + 1, fa.end());
    for (auto &x : fa)
        x /= p2;
 
    vector<long long> prod(p2);
    for (int i = 0; i < p2; i++)
        prod[i] = fa[i].real() + 0.5;
 
    return prod;
}


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vec<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        pref[i + 1] = pref[i] + (value < x);
    }

    vec<int> a(n + 1);
    vec<int> b(n + 1);
    for (auto x : pref) {
        a[x]++;
        b[n - x]++;
    }

    auto c = multiply(a, b);
    for (auto x : a)
        c[n] -= 1ll * x * (x + 1) / 2;

    for (int i = n; i <= 2 * n; i++)
        cout << c[i] << ' ';

    cout << '\n';
}