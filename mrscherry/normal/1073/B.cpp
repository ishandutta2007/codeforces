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
int A[200055];
int B[200055];
int lt[200055];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> A[i], lt[A[i]] = 1;
    for (int i = 1; i <= n; i++) cin >> B[i];
    int top = 1;
    for (int i = 1; i <= n; i++) {
        if (lt[B[i]]) {
            int ans = 0;
            while (A[top] != B[i]) lt[A[top]] = 0, ans++, top++;
            lt[B[i]] = 0;
            ans++, top++;
            cout << ans << ' ';
        }
        else cout << "0 ";
    }
}