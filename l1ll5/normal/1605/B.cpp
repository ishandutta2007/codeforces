#include <bits/stdc++.h>
using namespace std;
using LL = long long;
void work() {
    int n;
    string s;
    cin >> n >> s;
    string t;
    t = s;
    sort(t.begin(), t.end());
    int fl = 1;
    for (int i = 0; i < n; i += 1) {
        if (s[i] != t[i]) fl = 0;
    }
    if (fl) {
        cout << "0\n";
        return;
    }
    vector<int> ans;
    int l = 0, r = n - 1;
    while (l < r) {
        while (l < r && s[l] == '0') l++;
        if (l >= r) break;
        while (l < r && s[r] == '1') r--;
        if (l >= r) break;
        //cout << l << ' ' << s[l] << ' ' << r << ' ' << s[r] << endl;
        ans.push_back(l);
        ans.push_back(r);
        l++, r--;
        //cout << l << ' ' << s[l] << ' ' << r << ' ' << s[r] << endl;
    }
    sort(ans.begin(), ans.end());
    /*for (auto x : ans) cout << s[x] << ' ';
    cout << endl;*/
    for (int i = 0; i < ans.size() / 2; i += 1) {
        swap(s[ans[i]], s[ans[ans.size() - i - 1]]);
    }
    /*for (auto x : s) cout << x;
    cout << endl;*/
    cout << 1 << '\n';
    cout << ans.size() << ' ';
    for (auto x : ans) cout << x + 1 << ' ';
    cout << '\n';
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        work();
    }
}