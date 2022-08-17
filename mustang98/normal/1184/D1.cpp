#include <bits/stdc++.h>

#define F first
#define S second
#define MP make_pair
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;

const int max_n = 1333, inf = 1000111222;

int n, k, m, t;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> k >> m >> t;
    while (t--) {
        int tp, len;
        cin >> tp >> len;
        if (tp == 0) {
            if (k <= len) {
                n = len;
            } else {
                n -= len;
                k -= len;
            }
        } else {
            if (len <= k) {
                ++k;
            }
            ++n;
        }
        cout << n << " " << k << endl;
    }
    return 0;
}