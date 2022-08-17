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
    int T;
    cin >> T;
    while(T--) {
        ll d, m;
        cin >> d >> m;
        vector<ll> v;
        for (ll cur = 1;; cur *= 2) {
            if (d > cur) {
                v.PB(cur);
                d -= cur;
            } else {
                v.PB(d);
                break;
            }
        }
        ll ans = 1;
        for (int i = 0; i < v.size(); ++i) {
            ++v[i];
            ans *= v[i];
            ans %= m;
        }
        ans = (ans + m - 1) % m;
        cout << ans << endl;
    }

    return 0;
}