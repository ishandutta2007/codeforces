#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1;
ll inf = 6e18;

ll calc(int n, int k, int c9, int st) {
    bool over = 0;
    int taken = 0;
    for (int i = 0; i <= k; ++i) {
        if (st + i < 10) {
            taken += (st + i) + c9 * 9;
        } else {
            taken += (st + i - 10) + 1;
        }
    }
    if (taken > n) {
        return inf;
    }
    int lft = n - taken;
    if (lft % (k + 1)) {
        return inf;
    }
    lft /= k + 1;
    ll ans = 0;
    if (lft == 0) {
    } else if (lft <= 8) {
        ans = lft;
    } else {
        lft -= 8;
        ans = (lft % 9);
        for (int i = 0; i < lft / 9; ++i) {
            ans = (ans * 10 + 9);
        }
        ans = ans * 10 + 8;
    }
    for (int i = 0; i < c9; ++i) {
        ans = ans * 10 + 9;
    }
    ans = ans * 10 + st;
    return ans;
}

ll solve() {
    ll ans = inf;
    int n, k;
    cin >> n >> k;
    for (int c9 = 0; c9 <= 16; ++c9) {
        for (int st = 0; st <= 9; ++st) {
            ans = min(ans, calc(n, k, c9, st));
        }
    }
    return (ans  == inf ? -1 : ans);
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        cout << solve() << endl;
    }

    return 0;
}