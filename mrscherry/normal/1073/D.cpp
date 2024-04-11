#include <bits/stdc++.h>

#define szv(V) ((int)(V).size())
#define allv(V) ((V).begin(), ((V).end()))
#define sortv(V) sort(allv(V))
#define uniquev(V) V.erase(unique(allv(V)), (V).end())
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

const int iinf = 1e9;
const ll linf = 4e18;

ll gcd(ll x, ll y) { while (y) x %= y, swap(x, y); return x; }
pll operator+(pll a, pll b) { return pll(a.fs + b.fs, a.se + b.se); }
pll operator-(pll a, pll b) { return pll(a.fs - b.fs, a.se - b.se); }
ll operator*(pll a, pll b) { return a.fs * b.se - a.se * b.fs; }
int sign(ll x) { return x < 0 ? -1 : x > 0 ? 1 : 0; }
int ccw(pll a, pll b, pll c) { return sign(a * b + b * c + c * a); }
template <class T> void setmin(T &x, T y) { if (x > y) x = y; }
template <class T> void setmax(T &x, T y) { if (x < y) x = y; }
template <class T> void addval(T &x, T y) { x += y; }

int n;
ll T;
int A[200055];
ll fen1[200055];
ll fen2[200055];

void update(ll fen[], int i, int x) {
    while (i < 200005) {
        fen[i] += x;
        i += i & -i;
    }
}

ll get(ll fen[], int i) {
    ll s = 0;
    while (i) {
        s += fen[i];
        i -= i & -i;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> T;
    ll sum = 0;
    for (int i = 1; i <= n; i++) cin >> A[i], sum += A[i], update(fen1, i, 1), update(fen2, i, A[i]);
    
    ll ans = 0;
    int lt = n;
    while (lt) {
        ans += T / sum * lt;
        T %= sum;
        int x = 1;
        while (x <= n) {
            int s = x - 1, e = n;
            while (s < e) {
                int m = (s + e + 1) / 2;
                if (get(fen2, m) - get(fen2, x - 1) <= T) s = m;
                else e = m - 1;
            }
            ans += get(fen1, s) - get(fen1, x - 1);
            T -= get(fen2, s) - get(fen2, x - 1);
            if (s < n) {
                update(fen1, s + 1, -1);
                update(fen2, s + 1, -A[s + 1]);
                sum -= A[s + 1];
                lt--;
            }
            x = s + 2;
        }
    }
    cout << ans << '\n';
    return 0;
}