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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int no = 0;
    REP(i, s.length()) {
        if (s[i] == '(')no++;
        else no--;
    }
    if (no != 0) {
        cout << -1 << endl;
        return;
    }
    int now = 0;
    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == '(') {
            now++;
        }
        else {
            now--;
        }
        if (now < 0) {
            cnt++;
        }
        if (now == 0) {
            if (cnt != 0) {
                ans += cnt+1;
                cnt = 0;
            }
        }
    }
    cout << ans << endl;
}

#undef int
int main() {
    init();

    solve();
}