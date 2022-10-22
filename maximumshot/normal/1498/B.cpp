#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int LOG = 22;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n, W;
        cin >> n >> W;
        vector<int> cnt(LOG);
        for (int i = 0; i < n; i++) {
            int w;
            cin >> w;
            int log_ = 0;
            while (w > 1)
                log_++, w >>= 1;
            cnt[log_]++;
        }
        int res = 0, cur = W;
        for (int it = 0; it < n; it++) {
            int j = LOG - 1;
            while (j >= 0 && ((1 << j) > cur || cnt[j] == 0))
                j--;
            if (j >= 0) {
                cnt[j]--;
                cur -= 1 << j;
            } else {
                res++;
                cur = W;
                it--;
            }
        }
        if (cur < W)
            res++;
        cout << res << "\n";
    }

    return 0;
}