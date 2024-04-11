#include <bits/stdc++.h>

#define szv(V) ((int)(V).size())
#define allv(V) (V).begin(), (V).end()
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

int n;
pii ps[300005];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    int Fmx = -mod, Fmn = mod, Smx = -mod, Smn = mod;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i].fs >> ps[i].se;
        setmax(Fmx, ps[i].fs);
        setmin(Fmn, ps[i].fs);
        setmax(Smx, ps[i].se);
        setmin(Smn, ps[i].se);
    }
    int ans4 = (Fmx + Smx - Fmn - Smn) * 2;
    int ans3 = 0;
    for (int i = 1; i <= n; i++) {
        int F, S;
        tie(F, S) = ps[i];
        setmax(ans3, Fmx - F + Smx - S);
        setmax(ans3, Fmx - F + S - Smn);
        setmax(ans3, F - Fmn + Smx - S);
        setmax(ans3, F - Fmn + S - Smn);
    }
    ans3 *= 2;
    cout << ans3;
    for (int i = 4; i <= n; i++) cout << ' ' << ans4;
    return 0;
}