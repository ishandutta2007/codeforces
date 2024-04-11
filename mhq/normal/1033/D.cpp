#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = 505;
int n;
ll a[maxN];
ll pw(ll a, ll b) {
    if (b == 0) return 1;
    if (b & 1) return a * pw(a, b - 1);
    ll res = pw(a, b / 2);
    return res * res;
}
ll check(ll n, int t) {
    ll k = (ll)pow(n, 1.0 / t);
    ll l = max(1LL, k - 10);
    ll r = k + 10;
    for (ll x = l; x <= r; x++) {
        if (pw(x, t) == n) return x;
    }
    return -1;
}
vector < ll > fours;
map < ll, int > all;
vector < ll > primes;
void try_reduce(ll p) {
    if (p == 1) return ;
    vector < ll > cands;
    for (int i = 0; i < fours.size(); i++) {
        if (fours[i] % p == 0) {
            fours[i] /= p;
            cands.push_back(fours[i]);
            all[p]++;
        }
    }
    for (ll t : cands) try_reduce(t);
}
ll gcd(ll a, ll b) {
    while (a > 0 && b > 0) {
        if (a < b) swap(a, b);
        a %= b;
    }
    return (a + b);
}
map < ll, int > rest;
const int mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        bool ok = false;
        for (int j = 4; j >= 2; j--) {
            ll q = check(a[i], j);
            if (q != -1) {
                primes.push_back(q);
                all[q] += j;
                ok = true;
                break;
            }
        }
        if (ok) continue;
        fours.push_back(a[i]);
    }
    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    for (ll p : primes) try_reduce(p);
    for (int i = 0; i < fours.size(); i++) {
        for (int j = i + 1; j < fours.size(); j++) {
            ll d = gcd(fours[i], fours[j]);
            if (d != 1 && d != fours[i]) try_reduce(d);
        }
    }
    for (ll t : fours) {
        if (t == 1) continue;
        rest[t]++;
    }
    ll ans = 1;
    for (auto it : all) {
        ans = (ans * (it.second + 1)) % mod;
    }
    for (auto it : rest) {
        ans = (ans * (it.second + 1)) % mod;
        ans = (ans * (it.second + 1)) % mod;
    }
    cout << ans;
}