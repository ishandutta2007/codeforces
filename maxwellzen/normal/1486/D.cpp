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

int t, n, k, l, r, ans;
vi a, p;

void solve() {
    cin >> n >> k;
    a.resize(n);
    F0R(i, n) cin >> a[i];
    p.resize(n+1);
    l=1, r=n, ans=0;
    while (l <= r) {
        int m = (l+r)/2;
        p[0]=0;
        F0R(i, n) p[i+1] = p[i] + (a[i] >= m ? 1 : 0);
        bool works = false;
        set<pi> s[2];
        FOR(i, 1, n+1) {
            if (i>=k) s[(i-k)%2].insert(mp(p[i-k] - (i-k)/2 + 1, i-k));
            pi c0 = *s[0].begin(), c1 = *s[1].begin();
            if (s[0].size()>0 && p[i] - p[c0.S] >= (i - c0.S)/2 + 1) {
                works=true;
                break;
            }
            if (s[1].size()>0 && p[i] - p[c1.S] >= (i - c1.S)/2 + 1) {
                works=true;
                break;
            }
        }
        if (works) {
            l = m+1;
            ans=m;
        } else r = m-1;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
}