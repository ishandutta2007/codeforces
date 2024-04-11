
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// maximum element must be at most the sum of the remaining numbers.
// The sum of all numbers must be even
// is this condition sufficient? Yes, proof follows by induction.

int n;
ll a, m, sum;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    m = 0;
    for(int i = 0; i < n; i++) {
        cin >> a;
        sum += a;
        m = max(m, a);
    }
    cout << (m > sum - m || sum % 2 == 1 ? "NO" : "YES") << endl;
}