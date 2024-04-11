#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<bool> vb;
typedef vector<pair<int,int>> vpi;
 
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)
 
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define pi pair<int, int>
#define mp make_pair
#define F first
#define S second

template<class T> struct Seg { // comb(ID,b) = b
    const T ID = 1e18; T comb(T a, T b) { return min(a,b); }
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

int t, n, k;
vi x, a;
vll ans;
 
void solve() {
    cin >> n >> k;
    x.rsz(k); a.rsz(k);
    F0R(i, k) {cin >> x[i]; x[i]--;}
    F0R(i, k) cin >> a[i];
    Seg<ll> st1, st2;
    st1.init(n); st2.init(n);
    F0R(i, k) st1.upd(x[i], a[i]-x[i]);
    F0R(i, k) st2.upd(x[i], a[i]+x[i]);
    ans.rsz(n);
    F0R(i, n) {
        ans[i]=min(st1.query(0, i)+i, st2.query(i, n-1)-i);
    }
    F0R(i, n) cout << ans[i] << ' ';
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}