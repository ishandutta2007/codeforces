#include <bits/stdc++.h>

using namespace std;

int n;
int l[1005], r[1005];
vector <int> v;
int a[1005];

int L(int x) {
    int r = 0;
    for (int i = 1; i < x; ++i) r += (a[i] > a[x]);
    return r;
}
int R(int x) {
    int r = 0;
    for (int i = x + 1; i <= n; ++i) r += (a[i] > a[x]);
    return r;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> l[i];
    for (int i = 1; i <= n; ++i) cin >> r[i];
    for (int i = 1; i <= n; ++i) v.push_back(-l[i] - r[i]);
    sort(v.begin(), v.end());
    if (v.back() != 0) return cout << "NO" << endl, 0;
    for (int i = 1; i <= n; ++i) {
        if (l[i] + r[i] >= n) return cout << "NO" << endl, 0;
        a[i] = lower_bound(v.begin(), v.end(), -l[i] - r[i]) - v.begin() + 1;
    }
    for (int i = 1; i <= n; ++i) if (l[i] != L(i) || r[i] != R(i)) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) cout << a[i] << ' '; cout << endl;
    return 0;
}