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
    while (T--) {
        int n, k;
        cin >> n >> k;
        ll l = 0, r = 2e9;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (mid - mid / n >= k) {
                r = mid;
            } else {
                l = mid;
            }
        }
        cout << r << "\n";
    }

    return 0;
}