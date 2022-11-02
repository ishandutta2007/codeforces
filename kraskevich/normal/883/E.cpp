#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

set<char> was;
int n;

bool valid(const string& t, const string& s) {
    for (int i = 0; i < n; i++) {
        if (t[i] != '*' && s[i] != t[i])
            return false;
        if (was.count(s[i]) && t[i] == '*')
            return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    string t;
    cin >> t;
    for (char c : t)
        if (c != '*')
            was.insert(c);
    int m;
    cin >> m;
    vector<string> ss;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (valid(t, s))
            ss.push_back(s);
    }
    assert(ss.size());
    int ans = 0;
    m = ss.size();
    for (char c = 'a'; c <= 'z'; c++) {
        if (was.count(c))
            continue;
        vector<int> cnt(m);
        for (int j = 0; j < m; j++) 
            for (int i = 0; i < n; i++)
                if (ss[j][i] == c)
                    cnt[j] = 1;
        ans += accumulate(cnt.begin(), cnt.end(), 0) == m;
    }
    cout << ans << "\n";
}