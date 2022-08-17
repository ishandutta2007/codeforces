#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        ll sum = 0, x = 0;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            sum += a;
            x ^= a;
        }
        cout << 2 << "\n";
        cout << x << " " << sum + x << "\n";
    }

    return 0;
}