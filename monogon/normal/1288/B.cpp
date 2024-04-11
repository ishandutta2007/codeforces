
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// Suppose b is k digits long.
// conc(a, b) = a * 10^k + b
// a b + a + b = a * 10^k + b
// a (b + 1 - 10^k) = 0
// b = 10^k - 1

int t;
ll A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> A >> B;
        cout << A * (ll) log10(B + 1) << endl;
    }
}