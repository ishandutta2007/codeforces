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

int n, mx, mn;
vi a, mins;
Seg<ll> st1, st2;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    a.rsz(2*n);
    F0R(i, n) cin >> a[i];
    F0R(i, n) a[i+n]=a[i];
    mx=mn=a[0];
    F0R(i, n) {
        mx=max(mx, a[i]);
        mn=min(mn, a[i]);
    }
    if (mn*2 >= mx) {
        F0R(i, n) cout << -1 << ' ';
        cout << endl;
        return 0;
    }
    st1.init(2*n);
    F0R(i, 2*n) st1.upd(i, a[i]);
    mins.rsz(n, 1e9);
    F0R(i, n) {
        if (mn*2 >= a[i]) continue;
        int l=i+1, r=2*n-2, ans=2*n-1;
        while (l <= r) {
            int m = (l+r)/2;
            if (st1.query(i, m)*2 < a[i]) {
                ans=m;
                r=m-1;
            } else l=m+1;
        }
        mins[i]=ans;
    }
    st2.init(3*n);
    F0R(i, n) st2.upd(i, mins[i]);
    F0R(i, n) st2.upd(i+n, mins[i]+n);
    F0R(i, n) st2.upd(i+2*n, mins[i]+2*n);
    F0R(i, n) {
        int l=i+1, r=3*n-1, ans=i;
        while (l <= r) {
            int m = (l+r)/2;
            if (st2.query(i, m)>m) {
                ans=m;
                l=m+1;
            } else r=m-1;
        }
        cout << ans-i+1 << ' ';
    }
    cout << endl;
}