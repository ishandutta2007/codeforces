#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

bool solve() {
    string s;
    cin >> s;
    for (int i = 0, n = s.size() ; i < n ; ++ i) {
        int j = i;
        while (j < n && s[j] == s[i]) j ++;
        if (j == i + 1) return false;
        i = j - 1;
    }
    return true;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}