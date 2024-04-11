
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll s = 0, b = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            s += a[i];
            b ^= a[i];
        }
        ll A = ((ll) 1e16) + (s % 2);
        b ^= A; s += A;
        ll dif = b - s / 2;
        cout << 3 << endl << A << " " << dif << " " << dif << endl;
    }
}