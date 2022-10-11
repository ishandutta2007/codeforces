#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

namespace sieve {
    vector<int> primes;
    vector<int> smallest_factor;

    void init(int n) {
        smallest_factor.resize(n + 1);
        iota(smallest_factor.begin(), smallest_factor.end(), 0);

        for (int i = 2; i <= n; i++) {
            if (smallest_factor[i] == i)
                primes.emplace_back(i);

            for (int j = 0; j < int(primes.size()) && primes[j] <= smallest_factor[i] && primes[j] * i <= n; j++)
                smallest_factor[primes[j] * i] = primes[j];
        }
    }

    inline bool is_prime(int n) {
        if (n <= 1)
            return false;

        return smallest_factor[n] == n;
    }

    inline vector<pair<int, int>> get_factors(int n) {
        vector<pair<int, int>> factors;
        while (n != 1) {
            int prime = smallest_factor[n];
            factors.emplace_back(prime, 0);

            while (smallest_factor[n] == prime) {
                factors.back().second++;
                n /= prime;
            }
        }

        return factors;
    }
} // namespace sieve

using sieve::primes;
using sieve::smallest_factor;
using sieve::is_prime;
using sieve::get_factors;


int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;
    if (n == 1) {
        cout << r - l + 1 << '\n';
        return 0;
    }

    sieve::init(r);
    vector<int> deg(r + 1);
    vector<int> base(r + 1);
    for (int i = 2; i <= r; i++) {
        deg[i] = 1 + (smallest_factor[i] == smallest_factor[i / smallest_factor[i]] ?
            deg[i / smallest_factor[i]] : 0);

        base[i] = (smallest_factor[i] == smallest_factor[i / smallest_factor[i]] ? 
            base[i / smallest_factor[i]] : i / smallest_factor[i]);
    }

    vector<int> value(r + 1);
    value[1] = 1;
    for (int i = 2; i <= r; i++)
        value[i] = (deg[i] % (n - 1) == 0 ? value[base[i]] : value[i / smallest_factor[i]]
            * smallest_factor[i]);

    vector<int> cnt(r + 1);
    ll answer = 0;
    for (int i = l; i <= r; i++)
        answer += cnt[value[i]]++;

    cout << answer * 2 << '\n';
}