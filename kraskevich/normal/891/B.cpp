#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    vector<int> ans(n);
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        ans[a[i].second] = a[(i + 1) % n].first;

    for (int x : ans)
        cout << x << " ";
    cout << endl;
}