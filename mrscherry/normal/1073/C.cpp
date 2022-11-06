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

int n, fx, fy;
char op[200055];
int gox[300], goy[300];

bool check(int x) {
    int rx = 0, ry = 0;
    for (int i = x; i < n; i++) {
        rx += gox[op[i]];
        ry += goy[op[i]];
    }
    for (int i = x; i <= n; i++) {
        if (abs(fx - rx) + abs(fy - ry) <= x) return true;
        rx += gox[op[i - x]] - gox[op[i]];
        ry += goy[op[i - x]] - goy[op[i]];
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> op >> fx >> fy;
    if (((n ^ fx ^ fy) & 1) || n < abs(fx) + abs(fy)) {
        cout << "-1\n";
        return 0;
    }

    gox['U'] = 0; goy['U'] = 1;
    gox['D'] = 0; goy['D'] = -1;
    gox['L'] = -1; goy['L'] = 0;
    gox['R'] = 1; goy['R'] = 0;
    int s = 0, e = n;
    while (s < e) {
        int m = (s + e) / 2;
        if (check(m)) e = m;
        else s = m + 1;
    }
    cout << s << '\n';
    return 0;
}