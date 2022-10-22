#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;

ll gcd(ll a, ll b) { return a? gcd(b % a, a): b; }

int main()
{
    cin >> n;
    if (n == 1) { printf("1\n"); return 0; }
    ll g = 0;
    for (ll i = 1; i * i <= n; i++) if (n % i == 0) {
        if (i > 1) g = gcd(g, i);
        if (n / i > 1) g = gcd(g, n / i);
    }
    cout << g << endl;
    return 0;
}