#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 1e9;
const ll inf64 = 1e18;

int main() {

#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> q(n);
        for (int i = 0; i < n; i++)
            cin >> q[i];

        int res = 0;
        for (int l = 0, r = 0; r < n;) {
            int ptr = r;
            int any = 0;
            for (int i = l; i <= r; i++) {
                if (ptr + 1 < n)
                    any = 1;
                ptr++;
                while (ptr + 1 < n && q[ptr] < q[ptr + 1])
                    ptr++;
            }
            res += any;
            l = r + 1;
            r = ptr;
        }

        cout << res << "\n";
    }

    return 0;
}