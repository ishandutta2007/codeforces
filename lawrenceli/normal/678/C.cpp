#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}

int main() {
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;
    
    ll c = ll(a) * b / gcd(a, b);
    int na = n / a - n / c, nb = n / b - n / c;
    int nc = n / c;

    if (p > q) na += nc;
    else nb += nc;

    cout << ll(na) * p + ll(nb) * q << '\n';
}