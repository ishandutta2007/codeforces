#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int maxn = 200100;

int n, k, x;
int a[maxn], p[maxn], s[maxn];

int main() {
    cin >> n >> k >> x;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) p[i+1] = p[i] | a[i];
    for (int i=n-1; i>=0; i--) s[i] = s[i+1] | a[i];

    ll ans = 0;
    for (int i=0; i<n; i++) {
        ll cur = a[i];
        for (int j=0; j<k; j++) cur *= x;
        ans = max(ans, cur | p[i] | s[i+1]);
    }

    cout << ans << '\n';
}