#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 4e4 + 5;

bitset< N > prime, hlp;

ui calc(ll p, ll n) {
    ll x = p;
    ui res = 0;
    while(x <= n) {
        res += ui(n / x);
        x *= p;
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    prime.set();
    prime[0] = prime[1] = 0;

    for(int i = 2;i * i < N;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < N;j += i) {
            prime[j] = 0;
        }
    }

    vec< int > prs;

    for(int i = 0;i < N;i++) {
        if(prime[i]) prs.push_back(i);
    }

    int sz = (int)prs.size();

    ui A, B, C, D;
    int n;

    cin >> n >> A >> B >> C >> D;

    auto F = [&](ui p) -> ui {
        return A * (p * p * p) + B * (p * p) + C * p + D;
    };

    ui res = 0;

    for(int l = 2;l <= n;l += N) {
        int r = min(n, l + N - 1);
        hlp.set();
        for(int p : prs) {
            int x = l + (p - l % p) % p;
            while(x <= r) hlp[x - l] = x == p, x += p;
        }
        for(int p = l;p <= r;p++) {
            if(!hlp[p - l]) continue;
            ui cnt = calc(p, n);
            res += cnt * F(p);
        }
    }

    cout << res << "\n";

    return 0;
}