#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int a[maxN];
multiset < int > s;
int n;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        s.insert(a[i]);
    }
    for (int i = n; i >= 1; i--) {
        auto it = s.lower_bound(a[i] + 1);
        if (it != s.end()) {
            s.erase(it);
            ans++;
        }
        else {
            s.erase(s.begin());
        }
    }
    cout << ans;
    return 0;
}