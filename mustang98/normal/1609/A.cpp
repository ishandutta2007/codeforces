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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        vector<ll> v;
        int c2 = 0;
        for (int i = 0; i  <n; ++i) {
            int a;
            cin >> a;
            while (a % 2 == 0) {
                a /= 2;
                ++c2;
            }
            v.PB(a);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < c2; ++i) {
            v.back() *= 2;
        }
        ll ans = 0;
        for (ll x : v) {
            ans += x;
        }
        cout << ans << "\n";
    }


    return 0;
}