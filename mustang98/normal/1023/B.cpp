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

ll n, k;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    if (n == 1 || k == 1) {
        cout << 0;
        return 0;
    }
    if (n + (n - 1) < k) {
        cout << 0;
        return 0;
    }
    ll ans;
    ans = k / 2;
    if (k % 2 == 0) {
        --ans;
    }
    if (k > n) {
        ans -= (k - n - 1);
    }
    cout << ans << endl;
    return 0;
}