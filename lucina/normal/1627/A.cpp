#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
char s[150][150];
int n, m;
int x, y;

int solve() {
    cin >> n >> m >> x >> y;
    -- x, -- y;
    bool all_white = true;;
    bool exist = false;
    for (int i = 0 ; i < n ; ++ i) {
        cin >> s[i];
        all_white &= (count(s[i], s[i] + m, 'W') == m);
        for (int j = 0 ; j < m ; ++ j) {
            if ((i == x || j == y ) && (s[i][j] == 'B')) exist = true;
        }
    }
    if (all_white) return -1;
    if (s[x][y] == 'B') return 0;
    if (exist) return 1;
    return 2;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        cout << solve() << '\n';
    }
}
/*
    Hm, don't know what to write?
    Well, just have fun I suppose.
*/