#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<pi> vpi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define mp make_pair
#define F first
#define S second

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll MOD = 1e9+7;// 998244353;

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 1e9+1e8; T comb(T a, T b) { return min(a,b); }
    int n; vector<T> seg;
    void init(int _n) { n = _n; seg.assign(2*n,ID); }
    void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(int p, T val) { // set val at position p
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(int l, int r) {  // min on interval [l, r]
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};

int t, n;
vi a, f, b;
Seg<int> st;

void solve() {
    cin >> n;
    a.rsz(n); f.rsz(n); b.rsz(n);
    F0R(i, n) cin >> a[i];
    f[0]=a[0]; FOR(i, 1, n) f[i]=max(f[i-1], a[i]);
    b[n-1]=a[n-1]; R0F(i, n-1) b[i]=max(b[i+1], a[i]);
    st.init(n);
    F0R(i, n) st.upd(i, a[i]);
    int right = n-1;
    F0R(i, n-2) {
        while (right>i+1 && b[right]<f[i]) right--;
        if (right <= i+1) break;
        if (b[right] != f[i]) continue;
        if (a[i+1]<f[i]) continue;
        int l = i+3, r = right, ans = i+2;
        while (l <= r) {
            int m = (l+r)/2;
            if (st.query(i+1, m-1) >= f[i]) {
                ans=m;
                l=m+1;
            } else r = m-1;
        }
        if (f[i] == b[ans] && f[i] == st.query(i+1, ans-1)) {
            cout << "YES\n";
            cout << i+1 << ' ' << ans-i-1 << ' ' << n-ans << '\n';
            return;
        }
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}