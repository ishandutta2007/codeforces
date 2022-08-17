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
    ll r, d;
    cin >> r >> d;
    int ans = 0;
    int cntk;
    cin >> cntk;
    int x, y, rad;
    ll to = r;
    ll from = r - d;
    for (int i = 0; i < cntk; ++i) {
        cin >> x >> y >> rad;
        if (x * x + y * y <= (to - rad) * (to - rad) &&
            x * x + y * y >= (from + rad) * (from + rad)) {
                ++ans;
            }
    }
    cout << ans;
    return 0;
}