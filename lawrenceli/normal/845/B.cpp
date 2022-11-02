#include <bits/stdc++.h>

using namespace std;

int dfs(int i, string t, string s) {
    if (i == 6) {
        int ret = 0;
        for (int i = 0; i < 6; i++)
            ret += (t[i] != s[i]);
        if (t[0] + t[1] + t[2] != t[3] + t[4] + t[5])
            ret = 1000;
        return ret;
    } else {
        int ret = 1000;
        for (char c = '0'; c <= '9'; c++) {
            t[i] = c;
            ret = min(ret, dfs(i + 1, t, s));
        }
        return ret;
    }
}

int main() {
    string s; cin >> s;
    cout << dfs(0, s, s) << endl;
}