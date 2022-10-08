
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n, a[2 * N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        sort(a, a + 2 * n);
        cout << (a[n] - a[n - 1]) << endl;
    }
}