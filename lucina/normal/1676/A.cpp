#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;

/**
    Imagine array v_i - i
    The operation took place like
    0 -1 -2 -3 0 -1 -2 -3
    each zeros will be moved to next zero
    -1 -2 -3 0 -1 -2 -3 0
    and add 1 to everything
    0 -1 -2 0 0 -1 -2
    Well, it just shifting array to the left k times
*/

bool solve() {
    string s;
    cin >> s;
    return accumulate(s.begin(), s.begin() + 3, 0) == accumulate(s.begin() + 3, s.end(), 0);
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}