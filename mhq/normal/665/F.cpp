#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
// Primes up to 10^12 can be counted in ~1 second.
const int MAXN = 10000005; // MAXN is the maximum value of sqrt(N) + 2
bool prime[MAXN];
int prec[MAXN];
vector<int> P;

void init() {
    prime[2] = true;
    for (int i = 3; i < MAXN; i += 2) prime[i] = true;
    for (int i = 3; i*i < MAXN; i += 2){
        if (prime[i]){
            for (int j = i*i; j < MAXN; j += i+i) prime[j] = false;
        }
    }
    for(int i=1; i<MAXN; i++){
        if (prime[i]) P.push_back(i);
        prec[i] = prec[i-1] + prime[i];
    }
}

ll rec(ll N, int K) {
    if (N <= 1 || K < 0) return 0;
    if (N <= P[K]) return N-1;
    if (N < MAXN && 1ll * P[K]*P[K] > N) return N-1 - prec[N] + prec[P[K]];
    const int LIM = 250;
    static int memo[LIM*LIM][LIM];
    bool ok = N < LIM*LIM;
    if (ok && memo[N][K]) return memo[N][K];
    ll ret = N/P[K] - rec(N/P[K], K-1) + rec(N, K-1);
    if (ok) memo[N][K] = ret;
    return ret;
}

ll count_primes(ll N) { // less than or equal to
    if (N < MAXN) return prec[N];
    int K = prec[(int)sqrt(N) + 1];
    return N-1 - rec(N, K) + prec[P[K]];
}

ll n;
//pq (n / p)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    init();
    cin >> n;
    ll ans = 0;
    for (ll i = 2; i * i * i <= n; i++) {
        if (prime[i]) ans++;
    }
    ll f = 0;
    for (ll i = 2; i * i <= n; i++) {
        if (prime[i]) {
            f++;
            ans += count_primes(n / i);
        }
    }
    ans -= f * f;
    ans += (f * (f - 1)) / 2;
    cout << ans;
    return 0;
}