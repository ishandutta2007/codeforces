#include <bits/stdc++.h>

using namespace std;

int n;
int a[300005];
set <int> s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) if (a[i] > 1) s.insert(i);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += a[i] / 3;
        a[i] %= 3;
        s.erase(i);
        vector <int> del;
        for (auto it = s.begin(); it != s.end() && a[i]; ++it) {
            int j = *it;
            int add = min(a[i], a[j] / 2);
            ans += add;
            a[i] -= add;
            a[j] -= 2 * add;
            if (a[j] < 2) del.push_back(j);
        }
        for (auto j: del) s.erase(j);
    }
    cout << ans << endl;
    return 0;
}