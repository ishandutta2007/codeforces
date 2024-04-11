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
ll MOD = 998244353;

struct mi {
    ll v; explicit operator int() const { return (int)v; } // explicit -> don't silently convert to int
    mi() { v = 0; }
    mi(ll _v) { v = _v % MOD;
        if (v < 0) v += MOD; }
    friend bool operator==(const mi& a, const mi& b) { 
        return a.v == b.v; }
    friend bool operator!=(const mi& a, const mi& b) { 
        return !(a == b); }
    friend bool operator<(const mi& a, const mi& b) { 
        return a.v < b.v; }
    mi& operator+=(const mi& m) { 
        if ((v += m.v) >= MOD) v -= MOD; 
        return *this; }
    mi& operator-=(const mi& m) { 
        if ((v -= m.v) < 0) v += MOD; 
        return *this; }
    mi& operator*=(const mi& m) { 
        v = int((ll)v*m.v%MOD); return *this; }
    mi& operator/=(const mi& m) { return (*this) *= inv(m); }
    friend mi pow(mi a, ll p) {
        mi ans = 1; assert(p >= 0);
        for (; p; p /= 2, a *= a) if (p&1) ans *= a;
        return ans; }
    friend mi inv(const mi& a) { assert(a.v != 0); 
        return pow(a,MOD-2); }

    mi operator-() const { return mi(-v); }
    mi& operator++() { return *this += 1; }
    mi& operator--() { return *this -= 1; }
    friend mi operator+(mi a, const mi& b) { return a += b; }
    friend mi operator-(mi a, const mi& b) { return a -= b; }
    friend mi operator*(mi a, const mi& b) { return a *= b; }
    friend mi operator/(mi a, const mi& b) { return a /= b; }
};

int n, m, w;
vvb grid;
string s;
vector<mi> two, p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    grid.rsz(n, vb(m));
    F0R(i, n) {
        cin >> s;
        F0R(j, m) {grid[i][j] = (s[j]=='o'); if (grid[i][j]) w++;}
    }
    two.rsz(w+1);
    two[0]=1;
    FOR(i, 1, two.size()) two[i] = two[i-1]*2;
    p.rsz(max(m+1, n+1), 1);
    p[0] = inv(mi(4));
    FOR(i, 1, p.size()) if (i%2==0) p[i] = p[i-1] + inv(pow(mi(2), i+2)); else p[i] = p[i-1] - inv(pow(mi(2), i+2));
    mi ans = 0;
    F0R(i, n) {
        int c = 0;
        F0R(j, m) {
            if (grid[i][j]) c++;
            else c=0;
            if (c >= 2) ans += p[c-2];
        }
    }
    F0R(j, m) {
        int c = 0;
        F0R(i, n) {
            if (grid[i][j]) c++;
            else c = 0;
            if (c >= 2) ans += p[c-2];
        }
    }
    ans *= pow(mi(2), w);
    cout << (int)ans << '\n';
}
// 32 + 32 + 8 + 32 + 16