
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// In a column, we could just change all values for a cost of n.
// Otherwise, loop through all values in the column congruent
// to j mod m. Find the number of rotations it would need to
// be placed in the correct spot.
// Suppose there are k values that don't need to change
// if we rotate by l. The cost is (n - k) + l.
// Find minimum n - k + l.
// Complexity: O(mn).

const int N = 2e5 + 5;
ll n, m, a;
vector<ll> v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        v[i] = vector<ll>(n, 0);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a;
            a--;
            if(a % m == j && a < m * n) {
                v[j][((i - a / m + n) % n + n) % n]++;
            }
        }
    }
    ll ops = 0;
    for(int j = 0; j < m; j++) {
        ll M = n;
        for(int i = 0; i < n; i++) {
            M = min(M, n + i - v[j][i]);
        }
        ops += M;
    }
    cout << ops << endl;
}