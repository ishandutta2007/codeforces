#include <bits/stdc++.h>

using namespace std;

string s;
int n;
int flg = 0;
string ans;

void solve(int l, int r) {
    if (l > r) {
        flg = 1;
        return;
    }
    if (r - l <= 2) {
        ans += s[l];
        return;
    }
    vector <int> cnt(3, 0);
    ++cnt[s[l] - 'a'];
    ++cnt[s[l+1] - 'a'];
    ++cnt[s[r-1] - 'a'];
    ++cnt[s[r] - 'a'];
    for (int i = 0; i < 3; ++i) if (cnt[i] >= 2) {
        ans += (char)('a' + i);
        break;
    }
    solve(l + 2, r - 2);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    n = s.size();
    solve(0, n - 1);
    string pr = ans;
    if (!flg) pr.pop_back();
    reverse(ans.begin(), ans.end());
    pr += ans;
    cout << pr << endl;
    return 0;
}