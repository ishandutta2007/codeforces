#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n, s;
const int maxN = 2 * (int)1e5 + 10;
int a[maxN];
vector < int > sm;
vector < int > la;
int cnt = 0;
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == s) cnt++;
        else if (a[i] > s) la.push_back(a[i]);
        else sm.push_back(a[i]);
    }
    sort(la.begin(), la.end());
    sort(sm.begin(), sm.end());
    reverse(la.begin(), la.end());
    ll ans = 0;
    while (sm.size() >= (n + 1) / 2) {
        ans += s - sm.back();
        sm.pop_back();
    }
    while (la.size() >= (n + 1) / 2) {
        ans += la.back() - s;
        la.pop_back();
    }
    cout << ans;
    return 0;
}