#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000111, inf = 1000111222;

int m[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int mn = inf;
        for (int i = 0; i <n; ++i) {
            cin >> m[i];
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (mn < m[i]) {
                ++ans;
            }
            mn = min(mn, m[i]);
        }
        cout << ans << "\n";
    }

    return 0;
}