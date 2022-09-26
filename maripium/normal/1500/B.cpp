#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	assert((a - b) % g == 0); // else no solution
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    int N, M; int64_t K; cin >> N >> M >> K;

    vector<int> Aloc(2 * (N+M), -1);
    vector<int> Bloc(2 * (N+M), -1);

    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        Aloc[--a] = i;
    }

    for (int i = 0; i < M; ++i) {
        int a; cin >> a;
        Bloc[--a] = i;
    }
    int G = __gcd(N, M);

    vector<ll> mod(2 * (N+M), -1);
    for (int i = 0; i < 2 * (N+M); ++i) {
        if (Aloc[i] == -1 || Bloc[i] == -1) continue;
        if (Aloc[i] % G != Bloc[i] % G) continue;
        mod[i] = crt(Aloc[i], N, Bloc[i], M);

        assert(mod[i] % N == Aloc[i]);
        assert(mod[i] % M == Bloc[i]);
    }

    ll L = ll(N) * M / G;
    ll low = 0, high = 2e18;

    while (low < high) {
        ll mid = (low + high) >> 1;
        ll tot = mid;
        for (int i = 0; i < 2 * (N+M); ++i) if (mod[i] != -1) {
            ll cur = (mid / L) + (mid % L > mod[i]);
            tot -= cur;
        }

        if (tot >= K) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << low << '\n';

    return 0;
}