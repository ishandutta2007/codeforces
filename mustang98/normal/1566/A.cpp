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
    while(T--) {
        ll n, s;
        cin >> n >> s;
        ll l = 0, r = s + 2;
        ll a = n / 2, b = n / 2;
        if (n % 2 == 1) {
            ++b;
        } else {
            --a;
            ++b;
        }
        while(l + 1 < r) {
            ll mid = (l + r ) / 2;
            ll c = b * mid;
            if (c <= s) {
                l = mid;
            } else {
                r = mid;
            }
        }
        cout << l << "\n";
    }

    return 0;
}