
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int MAX_N = 3e5 + 5;
ll a[MAX_N];
int n, k, q;

int main() {
    cin >> n >> k >> a[0];
    q -= a[0];
    for(int i = 1; i < n; i++) {
        cin >> a[i];
        a[i - 1] = a[i] - a[i - 1];
    }
    q += a[n - 1];
    sort(a, a + (n - 1), std::greater<int>());
    for(int i = 0; i < k - 1; i++) {
        q -= a[i];
    }
    cout << q << endl;
}