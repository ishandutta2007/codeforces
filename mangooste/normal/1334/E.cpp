#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

const ll MOD = 998244353LL;
const int m = 100;

vector<ll> facts, rev_facts;
vector<ll> primes;

ll bin_pow(ll a, ll b) {
    if (b == 0)
        return 1;
    if (b & 1)
        return bin_pow(a, b - 1) * a % MOD;
    ll mid = bin_pow(a, b / 2);
    return mid * mid % MOD;
}

vector<pair<ll, ll>> get_prime_divisors(ll n) {
    vector<pair<ll, ll>> divs;
    ll m = n;
    for (ll i = 2; i * i <= n; i++) {
        ll cnt = 0;
        while (m % i == 0)
            cnt++, m /= i;
        if (cnt != 0)
            divs.push_back({ i, cnt });
    }
    if (m != 1)
        divs.push_back({ m, 1 });
    return divs;
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll get(ll v, ll u) {
    if (v == u)
        return 1;
    ll n = u / v;
    vector<int> cnts;
    for (auto i : primes) {
        int cnt = 0;
        while (n % i == 0)
            n /= i, cnt++;
        if (cnt != 0)
            cnts.push_back(cnt);
    }
    int sum = 0;
    ll ans = 1;
    for (auto i : cnts) {
        sum += i;
        ans *= rev_facts[i];
        ans %= MOD;
    }
    ans *= facts[sum];
    ans %= MOD;
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll D;
    cin >> D;
    facts.resize(m);
    facts[0] = 1;
    for (int i = 1; i < m; i++)
        facts[i] = facts[i - 1] * i % MOD;
    rev_facts.resize(m);
    for (int i = 0; i < m; i++)
        rev_facts[i] = bin_pow(facts[i], MOD - 2);
    vector<pair<ll, ll>> divs = get_prime_divisors(D);
    for (auto i : divs)
        primes.push_back(i.first);
    int q;
    cin >> q;
    while (q--) {
        ll v, u;
        cin >> v >> u;
        ll g = gcd(v, u);
        cout << get(g, v) * get(g, u) % MOD << '\n';
    }
}