
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int n, k, a[N], c[N], cnt[N], p[N];
vector<int> v[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    sort(a, a + n);
    for(int i = k; i > 0; i--) {
        p[i] = cnt[i] + p[i + 1];
    }
    int ans = 0;
    for(int i = 1; i <= k; i++) {
        cin >> c[i];
        ans = max(ans, (p[i] + c[i] - 1) / c[i]);
    }
    cout << ans << '\n';
    for(int i = 0; i < n; i++) {
        v[i % ans].push_back(a[i]);
    }
    for(int i = 0; i < ans; i++) {
        cout << (int) v[i].size() << ' ';
        for(int x : v[i]) {
            cout << x << ' ';
        }
        cout << '\n';
    }
}