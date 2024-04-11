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
    int t;
    cin >> t;
    while (t--) {
        int a, b, c , n;
        cin >> a >> b >> c >> n;
        int mx = max(max(a, b), c);
        int need = mx * 3 - a - b - c;
        if (need > n) {
            cout << "NO" << endl;
            continue;
        }
        n -= need;
        if (n % 3 == 0) {
            cout << "YES";
        } else {
            cout << "NO";
        }
        cout << "\n";
    }

    return 0;
}