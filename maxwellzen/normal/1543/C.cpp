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

int t;
long double c, m, p, v, hv;

long double exp(long double a, long double b) {
    long double ans = 1;
    if (a>=v) ans += a * exp(a-v, b+v);
    else ans += a;
    return ans;
}

long double exp(long double c, long double m, long double p) {
    long double ans = 1;
    if (c>=v+0.0000001) ans += c * (exp(c-v, m+hv, p+hv));
    else ans += c * (exp(m + c/2, p + c/2));
    if (m >= v+0.0000001) ans += m * (exp(c+hv, m-v, p+hv));
    else ans += m * (exp(c + m/2, p + m/2));
    return ans;
}
 
void solve() {
    cin >> c >> m >> p >> v;
    hv = v/2.0;
    long double ans;
    if (c==0) ans = exp(m, p);
    else if (m==0) ans = exp(c, p);
    else ans = exp(c, m, p);
    printf("%.9Lf\n", ans);
    // cout << '\n';
    // cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        solve();
    }
}