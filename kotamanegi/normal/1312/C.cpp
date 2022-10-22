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
    int n, k;
    cin >> n >> k;
    vector<int> inputs;
    int now_max = 0;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(a);
        now_max = max(now_max, a);
    }
    int geko = 1;
    while (geko * k <= now_max) {
        geko *= k;
    }
    while (geko != 0) {
        REP(i, inputs.size()) {
            if (inputs[i] - geko >= 0) {
                inputs[i] -= geko;
                break;
            }
        }
        geko /= k;
    }
    sort(ALL(inputs));
    if (inputs.back() == 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}

#undef int
int main() {
    init();
    int t;
    cin >> t;
    REP(tea,t)
    solve();
}