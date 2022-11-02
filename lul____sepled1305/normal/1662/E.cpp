#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long long ll;

const int N = (int)2e5 + 50;

struct BIT {
    int n, bit[N];


    void init(int _n) {
        n = _n;
        fill(bit, bit + n, 0);
    }
    void add(int x, int val) {
        for (int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    int get(int x) {
        int res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) res += bit[i];
        return res;
    }
} bit;

int n, p[N], loc[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) {
            cin >> p[i]; p[i]--;
            loc[p[i]] = i;
        }
        bit.init(n);
        rep(i, 0, n) bit.add(i, 1);
        ll res = 0;
        for (int i = n - 1; i >= 1; i--) {
            bit.add(loc[i], -1);
            int c = 0;
            if(loc[i - 1] < loc[i]) {
                c = bit.get(loc[i] - 1) - bit.get(loc[i - 1]);
            } else {
                c = bit.get(loc[i] - 1) + (i - bit.get(loc[i - 1]));
            }
            res += 1LL * c * (n - i);
        }
        cout << res << '\n';
    }
}