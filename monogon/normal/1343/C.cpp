
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll sum = 0, p = a[0];
        for(int i = 1; i < n; i++) {
            if((a[i] > 0) != (a[i - 1] > 0)) {
                sum += p;
                p = a[i];
            }else {
                p = max(p, a[i]);
            }
        }
        cout << sum + p << endl;
    }
}