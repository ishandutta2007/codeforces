
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n, k;
ll p;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> p >> k;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, a + n);
        for(int i = 1; i < k - 1; i++) {
            a[i] += a[i - 1];
        }
        for(int i = k; i < n; i++) {
            a[i] += a[i - k];
        }
        ll best = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] <= p) best = i + 1;
        }
        cout << best << endl;
    }
}