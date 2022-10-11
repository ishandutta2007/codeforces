#include <bits/stdc++.h>
using namespace std;

const int N = 1E6 + 5;

int n, a[N], sl[N];
pair<long long, int> ans;
long long cur = 0, add = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        cur += abs(i - a[i]);
        add += (i <= a[i] ? -1 : 1);
        sl[(a[i] - i + n) % n]++;
    }
    ans = {1E18, 0};
    for (int i = 0; i < n; i++) {
        ans = min(ans, {cur, i});
        add += 2 * sl[i];
        cur += add;
        int lst = a[(2 * n - 1 - i) % n];
        cur -= n - lst;
        cur += lst;
        add -= 2;
    }
    cout << ans.first << " " << ans.second << '\n';
}