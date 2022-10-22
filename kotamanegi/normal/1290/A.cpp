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
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    int ans = -1;
    if (m <= k + 1) {
        //ok
        REP(i, n) {
            if (i < m || i > inputs.size() - m - 1) {
                ans = max(ans, inputs[i]);
            }
        }
    }
    else {
        for (int left = 0; left <= k; ++left) {
            int right = inputs.size() - 1 - (k - left);
            int tmp = 1e18;
            int hoge = m - k - 1;
            for (int t = 0; t <= hoge; ++t) {
                int now_left = left + t;
                int now_right = right - (hoge - t);
                tmp = min(tmp, max(inputs[now_left], inputs[now_right]));
            }
            ans = max(ans, tmp);
        }
    }
    cout << ans << endl;
    return;
}
#undef int
int main() {
    init();
    int t;
    cin >> t;
    REP(i,t)
    solve();
}