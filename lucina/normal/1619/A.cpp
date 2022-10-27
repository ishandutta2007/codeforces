#include<bits/stdc++.h>
using namespace std;

bool solve() {
    string s;
    cin >> s;
    if (s.size() % 2) return false;
    int n = s.size();
    for (int i = 0 ; i < n / 2 ; ++ i) {
        if (s[i] != s[i + n / 2]) return false;
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