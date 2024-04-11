
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e5 + 5;
int t, n;
ll a[N], x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        ll sum = 0;
        int i = n - 1;
        for(; i >= 0; i--) {
            sum += a[i];
            if((n - i) * x > sum) break;
        }
        cout << n - i - 1 << endl;
    }
}