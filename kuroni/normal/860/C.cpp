#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 100005;

int n, t, e = 0;
bool chk[N];
string s;
vector<string> ve[2];
vector<int> ava[2];
deque<string> de[2];
vector<pair<string, string>> ans;

int type(string &s) {
    for (char &c : s) {
        if (!isdigit(c)) {
            return -1;
        }
    }
    if (s[0] == '0') {
        return -1;
    }
    int ret = atoi(s.c_str());
    if (ret <= 0 || ret > n) {
        return -1;
    } else {
        return ret > e;
    }
}

void rename(string s, string t) {
    ans.push_back({s, t});
    int c = type(s);
    if (c != -1) {
        ava[c].push_back(atoi(s.c_str()));
    }
    c = type(t);
    if (c != -1) {
        ava[c].pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s >> t;
        t = 1 - t;
        ve[t].push_back(s);
        e += (t == 0);
    }
    for (int i = 0; i < 2; i++) {
        for (string &s : ve[i]) {
            int t = type(s);
            if (t == -1) {
                de[i].push_back(s);
            } else {
                chk[atoi(s.c_str())] = true;
                if (t != i) {
                    de[i].push_front(s);
                }
            }
        }
    }
    if (de[0].empty() && de[1].empty()) {
        return cout << 0, 0;
    }
    for (int i = 1; i <= n; i++) {
        if (!chk[i]) {
            ava[i > e].push_back(i);
        }
    }
    if (ava[0].empty() && ava[1].empty()) {
        rename(de[0].front(), "kuroni");
        de[0].pop_front(); de[0].push_back("kuroni");
    }
    while (!de[0].empty() || !de[1].empty()) {
        if (!de[0].empty() && !ava[0].empty()) {
            rename(de[0].front(), to_string(ava[0].back()));
            de[0].pop_front();
        } else if (!de[1].empty() && !ava[1].empty()) {
            rename(de[1].front(), to_string(ava[1].back()));
            de[1].pop_front();
        }
    }
    cout << ans.size() << '\n';
    for (pair<string, string> &v : ans) {
        cout << "move " << v.fi << " " << v.se << '\n';
    }
}