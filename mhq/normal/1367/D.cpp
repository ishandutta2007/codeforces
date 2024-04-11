#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        vector < int > cnt(26);
        string s;
        cin >> s;
        for (char& c : s) {
            cnt[c - 'a']++;
        }
        int m;
        cin >> m;
        set < int > ss;
        vector < int > b(m);
        vector < int > gg;
        for (int& v : b) {
            cin >> v;
            ss.insert(v);
            gg.emplace_back(v);
        }
        int c = 26;
        vector < int > ans(m, -1);
        map < int, vector < int > > by;
        while (true) {
            bool fnd = false;
            vector < int > vv;
            for (int i = 0; i < b.size(); i++) {
                if (ans[i] == -1) {
                    int val = 0;
                    for (int j = 0; j < m; j++) {
                        if (ans[j] != -1) val += abs(i - j);
                    }
                    if (val == b[i]) {
                        vv.emplace_back(i);
                        by[c].emplace_back(i);
                        fnd = true;
                    }
                }
            }
            if (!fnd) break;
            for (int p : vv) ans[p] = c;
            c--;
        }
        string s_ans(m, 'a');
        c++;
        for (int i = 0; i < 26; i++) {
            if (by.count(c) && cnt[i] >= by[c].size()) {
                for (int to : by[c]) s_ans[to] = (char)(i + 'a');
                c++;
            }
        }
        cout << s_ans;
        cout << '\n';

    }
    return 0;
}