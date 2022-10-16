#include <bits/stdc++.h>

using namespace std;

int n, m;

int f[5005];

int cnt(vector <int> v) {
    int s = v.size();
    int r = 0;
    for (int i = 0; i < s; ++i) for (int j = 0; j < i; ++j) for (int k = 0; k < j; ++k)
        if (v[k] + v[j] == v[i]) ++r;
    return r;
}

int cal(int x, int n) {
    int a = (x - 1) / 2;
    int b = min(x - 1, n - x);
    int c = max(0, n - x - x);
    return a + b + c;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> m;
    f[3] = 1;
    for (int i = 4; i <= n + 1; ++i) f[i] = f[i-2] + i - 2;
    if (f[n] < m) return cout << -1 << endl, 0;
    vector <int> v;
    int k = 1;
    while (f[k] < m) v.push_back(k), ++k;
    v.push_back(k);
    v.push_back(k + 1);

    for (int i = 1; i <= k + 1; ++i) if (f[k + 1] - cal(i, k + 1) == m) {
        v.erase(find(v.begin(), v.end(), i));
        break;
    }

    int p = 1e9;
    while (v.size() < n) v.push_back(p), p -= k + 2;

    sort(v.begin(), v.end());
    for (auto x: v) cout << x << ' '; cout << endl;
    return 0;
}