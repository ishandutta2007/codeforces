#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M;
int a[5005], bad[5005];
set <int> bads;
int to[5005];
int val[5005];
int d[1000005];
int tot;
vi primes;
int f[5005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ff(i, 1, 1000000) d[i] = i;
    ff(i, 2, 1000) if (d[i] == i) ff(j, i, 1000000 / i) d[i*j] = i;
    ff(i, 2, 1000000) if (d[i] == i) primes.pb(i);
    cin >> N >> M;
    ff(i, 1, N) cin >> a[i];
    ff(i, 1, M) cin >> bad[i], bads.insert(bad[i]);
    ff(i, 1, N) {
        int tmp = a[i];
        for (int z = 0; 1ll * primes[z] * primes[z] <= a[i]; ++z) if (tmp % primes[z] == 0) {
            int cnt = 0;
            while (tmp % primes[z] == 0) ++cnt, tmp /= primes[z];
            if (bads.find(primes[z]) == bads.end()) tot += cnt; else tot -= cnt;
        }
        if (tmp > 1) {
            if (bads.find(tmp) == bads.end()) ++tot; else --tot;
        }
        to[i] = __gcd(to[i-1], a[i]);
        tmp = to[i];
        for (int z = 0; 1ll * primes[z] * primes[z] <= to[i]; ++z) if (tmp % primes[z] == 0) {
            int cnt = 0;
            while (tmp % primes[z] == 0) ++cnt, tmp /= primes[z];
            if (bads.find(primes[z]) == bads.end()) val[i] += cnt; else val[i] -= cnt;
        }
        if (tmp > 1) {
            if (bads.find(tmp) == bads.end()) ++val[i]; else --val[i];
        }
    }
    int ans = 0;
    ff(i, 1, N) {
        ff(j, 0, i - 1) f[i] = min(f[i], f[j] + (i - j) * val[i]);
        ans = min(ans, f[i]);
    }
    cout << tot - ans << endl;
    return 0;
}