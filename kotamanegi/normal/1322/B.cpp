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
    int ans = 0;
    vector<int> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
    }
    for (int q = 29; q >= 0; --q) {
        int check = 0;
        vector<int> cnt[2];
        REP(i, inputs.size()) {
            if ((1 << q) & inputs[i]) {
                cnt[1].push_back(inputs[i] % (1 << q));
            }
            else {
                cnt[0].push_back(inputs[i] % (1 << q));
            }
        }
        REP(i, 2) {
            sort(ALL(cnt[i]));
            int back = (int)cnt[i].size() - 1;
            REP(j, cnt[i].size()) {
                while (back >= 0&&cnt[i][j] + cnt[i][back] >= (1 << q)) {
                    back--;
                }
                int border = max(back, j);
                check += cnt[i].size() - border - 1;
            }
        }
        int now = (int)cnt[1].size()-1;
        for (int j = 0; j < cnt[0].size(); ++j) {
            while (now >= 0 && cnt[0][j] + cnt[1][now] >= (1 << q)) {
                now--;
            }
            check += now + 1;
        }
        if (check % 2) {
            ans += (1 << q);
        }
    }
    cout << ans << endl;
}

#undef int
int main() {
    init();

    solve();
}