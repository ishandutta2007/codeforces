
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll n, d, e;

int main() {
    ios::sync_with_stdio(false);
    // maximize x d + y 5e while staying below n
    cin >> n >> d >> e;
    ll M = n;
    for(int y = 0; y <= n / (5 * e); y++) {
        M = min(M, (n - y * 5 * e) % d);
    }
    cout << M << endl;
}