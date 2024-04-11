#include <bits/stdc++.h>

typedef long long ll;

const int INF = 2e9;
const int mod = 1e9 + 7;

using namespace std;

bool good() {
    string s;
    cin >> s;
    return s[0] == 'Y';
}

string name(int a) {
    string ans = "Aa";
    ans[0] = 'A' + a / 10;
    ans[1] = 'a' + a % 10;
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<string> ans;
    int last = 0;
    for(int i = 0; i < k - 1; ++i) {
        ans.push_back(name(++last));
    }
    for(int i = 0; i < n - k + 1; ++i) {
        ans.push_back(good() ? name(++last) : ans[i]);
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    solve();
    return 0;
}