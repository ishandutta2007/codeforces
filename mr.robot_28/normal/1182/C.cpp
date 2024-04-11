#include <bits/stdc++.h>
#define int long long
using namespace std;
pair <int, int> check(string s) {
    int o = 0, p = 0;
    for (auto i : s) {
        if (i == 'a' || i == 'e' || i == 'o' || i == 'i' || i == 'u') {
            o++;
            if (i == 'a')
                p = 0;
            if (i == 'e')
                p = 1;
            if (i == 'o')
                p = 2;
            if (i == 'i')
                p = 3;
            if (i == 'u')
                p = 4;
        }
    }
    return {o, p};
}

vector <string> dp[1000010][6];

vector <pair <string, string>> v;
vector <pair <string, string>> g;

vector <string> t;

vector <string> dp1[1000010];

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        pair <int, int> a;
        a = check(s);
        dp[a.first][a.second].push_back(s);
    }
    for (int i = 0; i < 1000010; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < dp[i][j].size(); k+=2) {
                if (k != dp[i][j].size() - 1)
                    v.push_back({dp[i][j][k], dp[i][j][k + 1]});
            }
            if (dp[i][j].size() % 2 == 1) {
                t.push_back(dp[i][j].back());
            }
        }
    }
    for (auto i : t) {
        pair <int, int> l = check(i);
        dp1[l.first].push_back(i);
    }
    for (int i = 0; i < 1000010; i++) {
        if (dp1[i].size() > 1) {
            for (int j = 0; j < dp1[i].size(); j+=2) {
                if (j != dp1[i].size() - 1)
                    g.push_back({dp1[i][j], dp1[i][j + 1]});
            }
        }
    }
    while (v.size() > g.size()) {
        g.push_back(v.back());
        v.pop_back();
    }
    cout << min(v.size(), g.size()) << endl;
    for (int i = 0; i < min(v.size(), g.size()); i++) {
        cout << g[i].first << " " << v[i].first << endl;
        cout << g[i].second << " " << v[i].second << endl;
    }
    return 0;
}