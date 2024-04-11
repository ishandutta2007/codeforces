
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n;
ll a, g;

ll factors(ll num) {
    if(num == 1) {
        return 1;
    }else if(num <= 3) {
        return 2;
    }

    ll res = 1;
    for(ll i = 2; i * i <= num; i++) {
        ll cnt = 0;
        while(num % i == 0) {
            num /= i;
            cnt++;
        }
        res *= (cnt + 1);
    }
    if(num > 1) {
        res *= 2;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> g;
    for(int i = 1; i < n; i++) {
        cin >> a;
        g = __gcd(g, a);
    }
    cout << factors(g) << endl;
}