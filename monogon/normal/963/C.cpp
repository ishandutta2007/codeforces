
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<pair<ll, ll>, ll> cnt;
    vector<ll> a, b;
    rep(i, 0, n) {
        ll w, h, c;
        cin >> w >> h >> c;
        cnt[{w, h}] += c;
        a.push_back(w);
        b.push_back(h);
    }
    sort(all(a));
    a.erase(unique(all(a)), a.end());
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    int r = sz(a), c = sz(b);
    rep(i, 0, r) rep(j, 0, c) {
        if(!cnt.count({a[i], b[j]})) {
            cout << 0 << '\n';
            return 0;
        }
    }
    vector<ll> gcdA(r, 0), gcdB(c, 0);
    rep(i, 0, r) {
        rep(j, 0, c) {
            gcdA[i] = gcd(gcdA[i], cnt[{a[i], b[j]}]);
        }
    }
    rep(j, 0, c) {
        rep(i, 0, r) {
            gcdB[j] = gcd(gcdB[j], cnt[{a[i], b[j]}]);
        }
    }
    rep(i, 0, r) {
        gcdA[i] = cnt[{a[i], b[0]}] / gcdB[0];
        rep(j, 0, c) {
            if(cnt[{a[i], b[j]}] != gcdA[i] * gcdB[j]) {
                cout << 0 << '\n';
                return 0;
            }
        }
    }
    ll G = 0;
    rep(i, 0, c) G = gcd(G, gcdB[i]);
    ll ans = 0;
    for(ll i = 1; i * i <= G; i++) {
        if(G % i == 0) {
            ans++;
            if(i * i != G) ans++;
        }
    }
    cout << ans << '\n';
}