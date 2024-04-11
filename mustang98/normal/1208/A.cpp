#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = -1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        ll a, b, n;
        cin >> a >> b >> n;
        if (n % 3 == 0) {
            cout << a << "\n";
        } else if (n % 3 == 1) {
            cout << b << "\n";
        } else {
            cout << (a ^ b) << "\n";
        }
    }

    return 0;
}