#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = (int)1e5 + 10;
map < ll, int > by_pref;
ll s[maxN];
int n, k;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        s[i] = s[i - 1] + x;
        by_pref[s[i]] = i;
    }
    if (s[n] % k != 0) {
        cout << "No";
        return 0;
    }
    int prv = 0;
    vector < int > ans;
    for (int i = 1; i <= k; i++) {
        ll need = (s[n] / k) * i;
        if (!by_pref.count(need)) {
            cout << "No";
            return 0;
        }
        int nxt = by_pref[need];
        ans.push_back(nxt - prv);
        prv = nxt;
    }
    cout << "Yes" << '\n';
    for (int v : ans) cout << v << " ";
    return 0;
}