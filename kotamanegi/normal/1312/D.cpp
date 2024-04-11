#define  _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:526000000")

#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144 * 4LL
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


#define int ll

unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

ll inv(int now) {
    ll b = MOD - 2;
    ll ans = 1;
    while (b) {
        if (b % 2) {
            ans *= now;
            ans %= MOD;
        }
        now *= now;
        now %= MOD;
        b /= 2;
    }
    return ans;
}

ll mae[500000];
ll gyaku[500000];

ll comb(int a, int b) {
    if (a < b) return 0;
    int ans = mae[a];
    ans *= gyaku[b];
    ans %= MOD;
    ans *= gyaku[a - b];
    ans %= MOD;
    return ans;
}

void solve() {
    mae[0] = 1;
    gyaku[0] = 1;
    for (int i = 1; i < 500000; ++i) {
        mae[i] = mae[i - 1] * i;
        mae[i] %= MOD;
        gyaku[i] = inv(mae[i]);
    }
    int n, m;
    cin >> n >> m;
    if (n == 2) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    int going = 1;
    REP(i, n - 3) {
        going *= 2LL;
        going %= MOD;
    }
    ll tmp = comb(m, n - 1);
    ans += tmp * going % MOD;
    ans %= MOD;
    ans *= n - 2;
    ans %= MOD;
    cout << ans << endl;
}

#undef int
int main() {
    init();
    solve();
}