#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int main() {
#ifdef FALSE
    freopen("input", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
    ll n, l, r;
    cin >> n >> l >> r;
    ll res = 0;
    int bits = 0;
    while ((1ll << bits) <= n)
        bits++;
    bits--;
    for (ll i = l; i <= r; i++) {
        int h = 0;
        ll cur = i;
        while (cur % 2 == 0) {
            cur /= 2;
            h++;
        }
        if (n & (1ll << (bits - h)))
            res++;
    }
    cout << res << endl;
}