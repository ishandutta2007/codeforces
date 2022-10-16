#include <bits/stdc++.h>

using namespace std;

int n;
string s[100005], t[100005];
bool has[100005][26];
map<pair<int, int>, vector<int>> mp;

int get(string a, int b, int m) {
    int ret = 0;
    for (auto c: a) ret = (1LL * ret * b + c) % m;
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> s[i] >> t[i];
        for (auto c: t[i]) has[i][c - 'a'] = true;
        while (s[i].size()) {
            char c = s[i].back();
            if (!has[i][c - 'a']) break;
            s[i].pop_back();
        }
        s[i] += ' ';
        for (char c = 'a'; c <= 'z'; ++c) if (has[i][c - 'a']) s[i] += c;
        int h1 = get(s[i], 515, 1007050321);
        int h2 = get(s[i], 289, 998244353);
        mp[make_pair(h1, h2)].push_back(i);
    }
    cout << mp.size() << endl;
    for (auto v: mp) {
        cout << v.second.size();
        for (auto x: v.second) cout << ' ' << x;
        cout << endl;
    }
    return 0;
}