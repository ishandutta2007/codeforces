
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// for each element, ask how many ops to make k of them?
// * A = ops to make all previous elements (k - 1)
// * B = ops to make all next elements (k + 1)
// if already K, answer 0
// if only from left, A + (k - cnt)
// if only from right, B + (k - cnt)
// if from both sides, A + B + (k - cnt)

// number of operations to make all val:
// (val - a[0]) + (val - a[1]) + ... + (val - a[j])
// idx * val - prefsum

const int N = 2e5 + 5;
int n, k;
ll a[N], pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a + n);
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i - 1] + a[i - 1];
    }
    ll ans = LLONG_MAX;
    for(int i = 0; i < n;) {
        int j = i + 1;
        while(j < n && a[j] == a[i]) j++;
        if(j - i >= k) {
            ans = min(ans, 0LL);
        }else {
            ll A = (a[i] - 1) * i - pref[i];
            ll B = (pref[n] - pref[j]) - (a[i] + 1) * (n - j);
            if(i + (j - i) >= k) {
                ans = min(ans, A + k - (j - i));
            }
            if((n - j) + (j - i) >= k) {
                ans = min(ans, B + k - (j - i));
            }
            ans = min(ans, A + B + k - (j - i));
        }
        i = j;
    }
    cout << ans << '\n';
}