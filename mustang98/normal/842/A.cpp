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
    ll l, r, x, y, k;
    cin >> l >> r >> x >> y >> k;
    for (int i = l ; i <= r; ++i) {
        if (i % k != 0) continue;
        ll need = i / k;
        if (need >= x && need <= y) {
            cout << "YES";
            return 0;
        }
    }
    cout << "NO";
    return 0;
}