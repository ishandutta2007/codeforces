
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

// for each value g from 1..n, there is a probability that gcd = g
// after steps so far.
// if it's g in one iteration, what will it be in the next iteration? some divisor of g
// so number of arrows is O(n log n)
// probability g -> d is what?
// P(d divides x and a larger divisor of g doesn't)
// we can compute for each d, P(d | x)
// P(gcd(x/d, g) = 1)
// 1 <= x / d <= floor(n / d)

// for each number d, what's the probability that the first k numbers
// are all multiples of d?
// sum_d P(d = gcd(a_1, ..., a_k))
// F(d) = P(d = gcd(a_1, ..., a_k))
// G(d) = P(d | a_1, ..., a_k)
// G(d) = sum_{d | c} F(c)
// sum_{k} sum_{d} mob(d) * (floor(n / d) / n)^k
// sum_{d} mob(d) / (1 - r(d))
// r(d) = floor(n / d) / n

const int N = 1e5 + 5, M = 1e9 + 7;
int n, mob[N];

ll powmod(ll a, ll b) {
    ll x = 1;
    while(b > 0) {
        if(b & 1) {
            x = (x * a) % M;
        }
        a = (a * a) % M;
        b /= 2;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll ans = 1;
    ll inv = powmod(n, M - 2);
    rep(i, 2, n + 1) {
        mob[i] = -1;
        int x = i;
        for(int j = 2; j * j <= x; j++) {
            if(x % j == 0) {
                mob[i] = -mob[i];
                x /= j;
                if(x % j == 0) mob[i] = 0;
                while(x % j == 0) x /= j;
            }
        }
        if(x > 1) mob[i] = -mob[i];
        ll r = ((n / i) * inv) % M;
        ans = (ans + mob[i] * r * powmod(1 - r, M - 2)) % M;
    }
    ans = (ans + M) % M;
    cout << ans << '\n';
}