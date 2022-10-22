#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

std::pair<std::vector<int>,std::vector<int>> primes_sieve(const int n) {
    std::pair<std::vector<int>,std::vector<int>> rv;
    std::vector<int>& primes = rv.first;
    std::vector<int>& sieve = rv.second;
    primes.reserve(n / 10);
    sieve.resize(n + 1, 0);
    if (n >=  1) sieve[0] = sieve[1] = -1;
    else if (n >= 0) sieve[0] = -1;
    if (n <= 4) {
        for(int i = 2; i <= n; ++i) {
            if (sieve[i] == 0) {
                primes.push_back(i);
                sieve[i] = i;
            }
            if (i == 2 && n == 4) sieve[4] = 2;
        }
        return rv;
    }
    for(int i = 2; i <= n; i += 2) sieve[i] = 2;
    for(int i = 3; i <= n; i += 6) sieve[i] = 3;
    primes.push_back(2); primes.push_back(3);
    const int n3 = n / 3;
    int i = 5;
    for(; i <= n3; i += 4) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            primes.push_back(i);
            int sz = primes.size();
            for(int j = 2;j < sz; ++j) {
                int p = primes[j];
                int x = i * p;
                if (x > n) break;
                sieve[x] = p;
            }
        } else {
            int si = sieve[i];
            for(int j = 2;; ++j) {
                int p = primes[j];
                int x = i * p;
                if (x > n) break;
                sieve[x] = p;
                if (p == si) break;
            }
        }
        i += 2;
        if (sieve[i] == 0) {
            sieve[i] = i;
            primes.push_back(i);
            int sz = primes.size();
            for(int j = 2;j < sz; ++j) {
                int p = primes[j];
                int x = i * p;
                if (x > n) break;
                sieve[x] = p;
            }
        } else {
            int si = sieve[i];
            for(int j = 2;; ++j) {
                int p = primes[j];
                int x = i * p;
                if (x > n) break;
                sieve[x] = p;
                if (p == si) break;
            }
        }
    }
    const int n2 = n - 2;
    for(; i <= n2; i += 4) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            primes.push_back(i);
        }
        i += 2;
        if (sieve[i] == 0) {
            sieve[i] = i;
            primes.push_back(i);
        }
    }
    if (i <= n) {
        if (sieve[i] == 0) {
            sieve[i] = i;
            primes.push_back(i);
        }
    }
    return rv;
}

auto [primes, sieve] = primes_sieve(100000);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        ll d;
        cin >> d;
        ll d1 = 1 + d;
        ll p1 = *lower_bound(all(primes), d1);
        ll p2 = *lower_bound(all(primes), p1 + d);
        cout << p1 * p2 << '\n';
    }
}