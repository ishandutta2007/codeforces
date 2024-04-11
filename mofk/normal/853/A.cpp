#include <bits/stdc++.h>

using namespace std;

int N, K;
long long a[300005];
long long s;
int ans[300005];
vector <pair <long long, int> > v;
set <int> se;

int main(void) {
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) cin >> a[i], s += a[i] * (K - i), v.push_back(make_pair(-a[i], i)), se.insert(i);
    sort(v.begin(), v.end());
    for (auto x: v) {
        int i = x.second;
        auto it = se.lower_bound(i - K);
        ans[i] = (*it) + K;
        s += a[i] * (*it);
        se.erase(it);
    }
    cout << s << endl;
    for (int i = 1; i <= N; ++i) cout << ans[i] << ' '; cout << endl;
}