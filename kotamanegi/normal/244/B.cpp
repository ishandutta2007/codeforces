#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(100);
}
#define int ll
int n;
int dfs(int now, int a, int b,int bit) {
    int ans = 0;
    if (now <= n) {
        if (bit == 3 || (b == -1 && bit == 1)) {
            ans = 1;
        }
        if (!(now == 0 && a == 0)) {
            ans += dfs(now * 10 + a, a, b, bit | 1);
        }
        if (b != -1) {
            ans += dfs(now * 10 + b, a, b, bit | 2);
        }
    }
    return ans;
}

void solve() {
    cin >> n;
    int ans = 0;
    REP(i, 10) {
        if (i != 0) {
            ans += dfs(0, i, -1,0);
        }
        for (int q = i + 1; q < 10; ++q) {
            ans += dfs(0, i, q,0);
        }
    }
    cout << ans << endl;
    return;
}
#undef int
int main() {
    init();
    solve();
}