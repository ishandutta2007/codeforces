#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

bool solve() {
    string s;
    cin >> s;
    if (s.back() != 'B') return false;
    int n = s.size();
    int sum = 0;
    for (int i = 0 ; i < n ; ++ i) {
        sum += (s[i] == 'A' ? 1 : -1);
        if (sum < 0) return false;
    }
    return true;
}

int main() {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/**
    long time no rated round
*/