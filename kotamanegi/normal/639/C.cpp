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
int dp[300000];
void solve(){
    int n, k;
    cin >> n >> k;
    int ans = 0;
    vector<int> inputs;
    REP(i, n+1) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    for (int i = n; i >= 1; --i) {
        dp[i - 1] = dp[i] * 2LL - inputs[i];
        if (llabs(dp[i - 1]) >= 1e18) {
            dp[i - 1] = 1e18;
        }
    }
    int now = 0;
    for (int i = 0; i < n+1; ++i) {
        if (llabs((dp[i]*2LL) + (now)) <= k) {
            if(i != n||(dp[i]*2LL)+now != 0)
            ans++;
        }
        now -= inputs[i];
        if (llabs(now) % 2 != 0) {
            break;
        }
        now /= 2LL;
    }
    cout << ans << endl;
}
#undef int
int main() {
    init();
    solve();
}