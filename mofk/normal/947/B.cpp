#include <bits/stdc++.h>

using namespace std;

int n;
long long v[100005];
long long t[100005];
long long temp[100005];
long long full[100005];
long long rem[100005];
long long ans[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> t[i];
    for (int i = 1; i <= n; ++i) {
        v[i] += temp[i-1];
        temp[i] = temp[i-1] + t[i];
    }

    for (int i = 1; i <= n; ++i) {
        int pos = upper_bound(temp + i, temp + n + 1, v[i]) - temp - 1;
        ++full[pos]; --full[i-1];
        rem[pos + 1] += v[i] - temp[pos];
    }

    for (int i = n; i >= 1; --i) {
        full[i] += full[i+1];
        //cout << full[i] << ' ' << rem[i] << endl;
        ans[i] = t[i] * full[i] + rem[i];
    }
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
}