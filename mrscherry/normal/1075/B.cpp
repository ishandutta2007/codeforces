#include <bits/stdc++.h>

#define szv(V) ((int)(V).size())
#define allv(V) ((V).begin(), ((V).end()))
#define sortv(V) sort(allv(V))
#define uniquev(V) (V).erase(unique(allv(V)), (V).end())
#define compv(V) sortv(V), uniquev(V)
#define fs first
#define se second
#define pb push_back
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int mod = 1e9 + 7;
const ll inf = 4e18 + 5;

ll gcd(ll x, ll y) { while (y) x %= y, swap(x, y); return x; }
pll operator+(pll a, pll b) { return pll(a.fs + b.fs, a.se + b.se); }
pll operator-(pll a, pll b) { return pll(a.fs - b.fs, a.se - b.se); }
ll operator*(pll a, pll b) { return a.fs * b.se - a.se * b.fs; }
template <class T> int sign(T x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
int ccw(pll a, pll b, pll c) { return sign((b - a) * (c - b)); }
template <class T> void setmin(T &x, T y) { if (x > y) x = y; }
template <class T> void setmax(T &x, T y) { if (x < y) x = y; }
template <class T> void addval(T &x, T y) { x += y; x %= mod; }

int n, m;
int X[200005];
int T[200005];
int L[200005];
int R[200005];
vector<int> taxi;
int ans[200005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n + m; i++) cin >> X[i];
    for (int i = 1; i <= n + m; i++) cin >> T[i];
    for (int i = 1; i <= n + m; i++) {
        if (T[i]) taxi.push_back(X[i]);
        else L[i] = szv(taxi) - 1;
    }
    for (int i = 1; i <= n + m; i++) {
        if (T[i]) continue;
        R[i] = lower_bound(taxi.begin(), taxi.end(), X[i]) - taxi.begin();
        ll Ld = L[i] < 0 ? inf : X[i] - taxi[L[i]];
        ll Rd = R[i] < szv(taxi) ? taxi[R[i]] - X[i] : inf;
        if (Ld <= Rd) ans[L[i]]++;
        else ans[R[i]]++;
    }
    for (int i = 0; i < m; i++) cout << ans[i] << ' ';
    return 0;
}