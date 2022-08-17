#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

ll m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    while(q--) {
        int n;
        ll k;
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
        }
        sort(m, m + n);
        ll res = m[0] + k;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (abs(m[i] - res) > k) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << res << endl;
        } else {

            cout << -1 << endl;
        }
    }

    return 0;
}