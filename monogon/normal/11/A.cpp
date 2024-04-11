
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2005;
int n;
ll d, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for(int i = 1; i < n; i++) {
        if(a[i] <= a[i - 1]) {
            int ops = 1 + (a[i - 1] - a[i]) / d;
            a[i] += ops * d;
            ans += ops;
        }
    }
    cout << ans << endl;
}