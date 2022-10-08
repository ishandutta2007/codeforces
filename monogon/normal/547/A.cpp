
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 1e6 + 5;
int m;
ll h1, a1, X1, Y1, h2, a2, X2, Y2;
int vis1[N], vis2[N];

ll mod(ll a, ll m) {
    return (a % m + m) % m;
}
ll euclid(ll a, ll b, ll &x, ll &y) {
    ll xx = y = 0;
    ll yy = x = 1;
    while(b) {
        ll q = a / b;
        ll t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}
pair<ll, ll> crt(ll r1, ll m1, ll r2, ll m2) {
    ll s, t;
    ll g = euclid(m1, m2, s, t);
    if(r1 % g != r2 % g) return {0, -1};
    ll M = m1 / g * m2;
    return {mod(mod(s * r2, M) * (m1 / g) + mod(t * r1, M) * (m2 / g), M), M};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> h1 >> a1 >> X1 >> Y1 >> h2 >> a2 >> X2 >> Y2;
    fill(vis1, vis1 + m, -1);
    fill(vis2, vis2 + m, -1);
    int it = 0;
    rep(i, 0, m + 2) {
        if(h1 == a1 && h2 == a2) {
            cout << it << '\n';
            return 0;
        }
        h1 = (X1 * h1 + Y1) % m;
        h2 = (X2 * h2 + Y2) % m;
        it++;
    }
    vi ve1, ve2;
    int hh1 = h1, hh2 = h2;
    while(true) {
        ve1.push_back(hh1);
        hh1 = (X1 * hh1 + Y1) % m;
        if(hh1 == h1) break;
    }
    while(true) {
        ve2.push_back(hh2);
        hh2 = (X2 * hh2 + Y2) % m;
        if(hh2 == h2) break;
    }
    int idx1 = find(all(ve1), a1) - ve1.begin();
    int idx2 = find(all(ve2), a2) - ve2.begin();
    if(idx1 == sz(ve1) || idx2 == sz(ve2)) {
        cout << "-1\n";
        return 0;
    }
    // it = idx1 (mod sz1)
    // it = idx2 (mod sz2)
    // CRT
    auto pa = crt(idx1, sz(ve1), idx2, sz(ve2));
    if(pa.second == -1) {
        cout << "-1\n";
        return 0;
    }
    cout << it + pa.first << '\n';
}