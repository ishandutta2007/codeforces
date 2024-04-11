#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll sum_digits(ll n) {
    ll res = 0;
    for (; n > 0; n /= 10)
        res += n % 10;
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    ll n, s;
    cin >> n >> s;
    ll low = s;
    ll high = 1000 + s;
    ll res = max(0ll, n - high);
    for (ll x = low; x <= min(n, high); x++)
        if (x - sum_digits(x) >= s)
            res++;
    cout << res << "\n";
}