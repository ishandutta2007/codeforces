
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 105;
int t, n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        for(int i = n - 1; i >= 0; i--) cout << a[i] << " ";
        cout << "\n";
    }
}