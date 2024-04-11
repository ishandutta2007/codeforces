#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;
const char TE[4][2] = {{'0', '0'}, {'5', '2'}, {'0', '5'}, {'5', '7'}};

long long n;

pair<int, string> solve(string s, int ind) {
    int ans = 0;
    if (ind == 0) {
        if (s.size() == 1) {
            return {0, s};
        } else {
            bool chk = false;
            for (int j = 1; j < s.size() && !chk; j++) {
                if (s[j] != '0') {
                    chk = true;
                    for (int k = j; k > 1; k--) {
                        swap(s[k], s[k - 1]);
                        ans++;
                    }
                }
            }
            if (!chk) {
                return {INF, s};
            }
        }
    }
    for (int j = ind; j < s.size() - 1; j++) {
        swap(s[j], s[j + 1]);
        ans++;
    }
    s.pop_back();
    return {ans, s};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    if (n < 10) {
        return cout << -1, 0;
    }
    string s = to_string(n);
    int ans = INF;
    for (int te = 0; te < 4; te++) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == TE[te][0]) {
                pair<int, string> tmp = solve(s, i);
                for (int j = 0; j < tmp.second.size(); j++) {
                    if (tmp.second[j] == TE[te][1]) {
                        pair<int, string> fin = solve(tmp.second, j);
                        ans = min(ans, tmp.first + fin.first);
                    }
                }
            }
        }
    }
    cout << (ans == INF ? -1 : ans);
}