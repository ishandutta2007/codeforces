#include <bits/stdc++.h>

using namespace std;

void go(int i, vector<int> &a, vector<int> &s, vector<int> &ans) {
    ans.push_back(i + 1);
    int v = a[i+1] ^ a[i+2] ^ a[i+3];
    a[i+1] = a[i+2] = a[i+3] = v;
    s[i + 2] = s[i];
    s[i + 1] = s[i + 3];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0);
        vector<int> s(n + 1, 0);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) s[i] = s[i-1] ^ a[i];
        if (s[n] != 0) {
            cout << "NO" << '\n';
            continue;
        }
        vector<int> ans;
        int posx = -1;
        for (int i = 1; i <= n; i += 2) if (s[i] == 0) posx = i;
        if (posx == -1) {
            cout << "NO" << '\n';
            continue;
        }
        for (int i = posx; i >= 3; i -= 2) go(i - 3, a, s, ans);
        for (int i = posx; i + 3 <= n; i += 2) go(i, a, s, ans);
        for (int i = 0; i + 3 <= n; i += 2) go(i, a, s, ans);
        for (int i = 1; i <= n; ++i) assert(a[i] == 0);
        cout << "YES" << '\n' << ans.size() << '\n';
        for (auto x: ans) cout << x << ' ';
        cout << '\n';
    }
    return 0;
}