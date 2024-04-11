#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111222, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            if (n == 2) {
                cout << -1 << "\n";
                continue;
            } else {
                cout << n / 4 << "\n";
                continue;
            }
        } else {
            if (n <= 7 || n == 11) {
                cout << -1 << "\n";
            } else {
                int ans = 1;
                n -= 9;
                ans += (n / 4);
                cout << ans << "\n";
            }
        }
    }
    return 0;
}