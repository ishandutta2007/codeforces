#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#pragma comment (linker, "/STACK:526000000")

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

void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(20);
}


unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}


#define int long long

int dp[3000][3000];

void solve() {
    int n, h, l, r;
    cin >> n >> h >> l >> r;
    vector<int> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    REP(i, inputs.size()+2) {
        REP(q, h) {
            dp[i][q] = -1e9;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < inputs.size(); ++i) {
        REP(q, h) {
            for (int j = -1; j <= 0; ++j) {
                int next_go = (q + j + inputs[i]) % h;
                int val = dp[i][q];
                if (next_go >= l && next_go <= r) {
                    val++;
                }
                dp[i + 1][next_go] = max(dp[i + 1][next_go], val);
            }
        }
    }
    int ans = -1;
    REP(i, h) {
        ans = max(ans, dp[inputs.size()][i]);
    }
    cout << ans << endl;
}
#undef int
int main() {
    init();
    solve();
}