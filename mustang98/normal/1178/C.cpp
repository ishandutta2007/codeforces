#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1011, inf = 1000111222;

const ll mod = 998244353LL;


int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b;
    cin >> a >> b;
    int p = a + b;
    ll ans = 1;
    for (int i = 0; i < a + b; ++i) {
        ans *= 2;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}