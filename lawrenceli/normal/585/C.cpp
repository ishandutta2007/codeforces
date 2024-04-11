#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 100;

ll num[maxn], cnt;

ll gcd(ll a, ll b) {
    if (!b) return a;
    if (a / b > 0) num[cnt++] = a / b;
    return gcd(b, a%b);
}

int main() {
    ll x, y;
    cin >> x >> y;
    ll g = gcd(x, y);
    if (g > 1) cout << "Impossible\n";
    else {
        char c = x < y ? 'B' : 'A';
        for (int i = 0; i < cnt; i++) {
            if (i == cnt - 1) cout << num[i]-1 << c;
            else cout << num[i] << c;
            c = c == 'A' ? 'B' : 'A';
        }
        cout << '\n';
    }
}