
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1005;
int n;
ll a[N][N];

// a1 a2
// a2 a3
// a3 a1

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    ll d = a[0][1];
    for(int i = 2; i < n; i++) {
        d = __gcd(d, a[0][i]);
    }
    // a[0] = d / k for some integer k
    // a[1] = a[0][1] * k / d
    // a[2] = a[0][2] * k / d

    // a[1][2] = a[0][1] * a[0][2] * k^2 / d^2
    // k^2 = d^2 * a[1][2] / (a[0][1] * a[0][2])
    ll k = sqrt(a[1][2] / ((a[0][1] / d) * (a[0][2] / d)));

    cout << d / k;
    for(int i = 1; i < n; i++) {
        cout << " " << a[0][i] * k / d;
    }
    cout << endl;
}