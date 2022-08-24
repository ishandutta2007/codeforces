#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
string s;
vector < int > all;
ll ans = 0;
const int maxN = (int)1e5 + 10;
int pref[maxN], suf[maxN];
void solve(int pos) {
    ans += 1 + (1LL * m - 1) * n;;
}
int lst[maxN], fst[maxN], num[maxN];
int go(int a, int b) {
    if ((a + 1) == b) return 2;
    for (int j = a; j <= b; j += 2) {
        if (s[j] != s[a]) return 1;
    }
    for (int j = a + 1; j <= b; j += 2) {
        if (s[j] != s[a + 1]) return 1;
    }
    return 2;
}
int longest[maxN];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    cin >> s;
    int cnt = 0;
    int sz = 0;
    for (int i = 0; i < n; i++) {
        if ((i == 0) || (s[i] != (s[i - 1]))) {
            sz++;
            all.push_back(i);
        }
        num[i] = sz;
    }
    for (auto t : all) solve(t);
    for (int i = 0; i < n; i++) {
        if ((i == 0) || (s[i] != (s[i - 1]))) {
            fst[num[i]] = i;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if ((i == (n - 1)) || (s[i] != s[i + 1])) {
            lst[num[i]] = i;
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (i + 2 >= n || s[i] != s[i + 2]) longest[i] = 1;
        else longest[i] = longest[i + 2] + 1;
    }
    for (int i = 0; i < n; i++) {
        if (i != lst[num[i]]) continue;
        if (i == n - 1) continue;
        int len1 = longest[i];
        int len2 = longest[i + 1];
        ans -= (min(longest[i] - 1, longest[i + 1]));
        ans -= min(longest[i], longest[i + 1]);
    }
    ans -= sz;
    cout << ans;
    return 0;
}