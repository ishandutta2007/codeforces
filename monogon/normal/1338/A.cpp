
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
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        ll m = LLONG_MAX;
        ll dif = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(i < n - 1) dif = max(dif, a[i] - m);
            m = min(m, a[i]);
        }
        if(dif == 0) {
            cout << 0 << '\n';
        }else {
            cout << (int) log2(dif) + 1 << '\n';
        }
    }
}