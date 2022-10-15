#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(answer) { cout << (answer) << '\n'; return; }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<int> primes;
    for (int p = 2; p <= n; ++p) {
        if (n % p != 0) continue;
        bool isPrime = true;
        for (int d = 2; d * d <= p; ++d) {
            if (p % d == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(p);
    }
    int sz = primes.size();
    vector<vector<ll>> programs(sz);
    multiset<ll> u;
    for (int i = 0; i < sz; ++i) {
        int p = primes[i];
        programs[i].assign(n / p, 0);
        for (int j = 0; j < n; ++j) programs[i][j % (n / p)] += a[j];
        for (ll x: programs[i]) u.insert(x * (n / p));
    }
    cout << *u.rbegin() << '\n';
    for (int tc = 0; tc < q; ++tc) {
        int p, x;
        cin >> p >> x;
        --p;
        for (int i = 0; i < sz; ++i) {
            u.erase(u.find(programs[i][p % (n / primes[i])] * (n / primes[i])));
            programs[i][p % (n / primes[i])] -= a[p];
        }
        a[p] = x;
        for (int i = 0; i < sz; ++i) {
            programs[i][p % (n / primes[i])] += a[p];
            u.insert(programs[i][p % (n / primes[i])] * (n / primes[i]));
        }
        cout << *u.rbegin() << '\n';
    }
}