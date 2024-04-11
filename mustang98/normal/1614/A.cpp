#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    while (T--) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        int ans = 0;
        vector<int> v;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if (x >= l && x <= r) {
                v.PB(x);
            }
        }
        sort(v.begin(), v.end());
        for (int x : v) {
            if (x <= k) {
                ++ans;
                k -= x;
            }
        }
        cout << ans << "\n";
    }


    return 0;
}