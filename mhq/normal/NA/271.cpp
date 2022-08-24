#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 4 * (int)1e5 + 100;
int a[maxN];
ll I;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> I;
    I *= 8;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    I /= n;
    sort(a + 1, a + n + 1);
    int k = (1 << min((int)I, 20));
    multiset < int > s;
    int l = 1;
    int ans = n + 10;
    int diff = 0;
    for (int i = 1; i <= n; i++) {
        s.insert(a[i]);
        if (i == 1 || a[i] != a[i - 1]) diff++;
        while (diff > k) {
            s.erase(s.find(a[l]));
            if (l == i || a[l] != a[l + 1]) diff--;
            l++;
        }
        ans = min(ans, n - (i - l + 1));
    }
    cout << ans;
    return 0;
}