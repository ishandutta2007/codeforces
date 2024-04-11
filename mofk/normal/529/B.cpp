#include <bits/stdc++.h>

using namespace std;

int n;
int w[1005], h[1005];
int bnd;
vector <int> val;

int solve(int x) {
    int rem = n / 2, tot = 0;
    vector <int> v;
    for (int i = 0; i < n; ++i) {
        if (h[i] > x) tot += h[i], --rem;
        else if (w[i] > x) tot += w[i];
        else tot += w[i], v.push_back(h[i] - w[i]);
    }
    if (rem < 0) return (int)2e9;
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size() && i < rem; ++i) if (v[i] < 0) tot += v[i];
    return tot * x;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> h[i];
        bnd = max(bnd, min(w[i], h[i]));
        val.push_back(w[i]); val.push_back(h[i]);
    }
    int ans = 2e9;
    for (int i = 0; i < val.size(); ++i) if (val[i] >= bnd) ans = min(ans, solve(val[i]));
    cout << ans << endl;
}