#include<bits/stdc++.h>
using namespace std;
constexpr int ALPHA = 26;
int to_int (char x) {
    return x - 'a';
}

int solve (string s, int x) {
    int n = int(s.size());
    if (n == 1) return to_int(s[0]) == x ? 0 : 1;

    int fi = 0, se = 0;
    string t;
    for (int i = 0 ; i < n / 2 ; ++ i) {
        if (to_int(s[i]) != x) ++ fi;
    }
    for (int i = n - 1 ; i >= n / 2 ; -- i) {
        if (to_int(s[i]) != x) ++ se;
        t += s[i];
        s.pop_back();
    }

    fi += solve(t, x + 1);
    se += solve(s, x + 1);
    return min(fi, se);
}

int n;
string s;

void solve () {
    cin >> n >> s;

    cout << solve(s, 0) << '\n';
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t -- ) {
            solve();
    }

}