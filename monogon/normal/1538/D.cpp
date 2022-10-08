
#pragma GCC optimize("O3")
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

vector<long long> primes;
const int N = 32'000;
bool p[N];

void sieve() {
    fill(p, p + N, true);
    for(int i = 2; i < N; i++) {
        if(p[i]) {
            primes.push_back(i);
            for(int j = 2 * i; j < N; j += i) {
                p[j] = false;
            }
        }
    }
}

int cnt(long long n) {
    int c = 0;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            c++;
            n /= d;
        }
    }
    if (n > 1) c++;
    return c;
}

void solve() {
    ll a, b, k;
    cin >> a >> b >> k;
    if(k == 1) {
        if(a != b && (a % b == 0 || b % a == 0)) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }else {
        int c = cnt(a) + cnt(b);
        if(c >= k) {
            cout << "YES\n";
        }else {
            cout << "NO\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    sieve();
    int te;
    cin >> te;
    while(te--) solve();
}