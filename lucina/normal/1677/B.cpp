#include<bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 10;
int n, m;
string s;
int r[nax];

void solve() {
    cin >> n >> m >> s;
    int sz = n * m;
    int c = 0;

    int lst_1 = -nax;
    fill(r, r + m, 0);
    for (int i = 0 ; i < sz ; ++ i) {
        if (s[i] == '1' || i - lst_1 < m)
            r[i % m] += 1;
        if (s[i] == '1') {
            if (i < m || (s[i - m] == '0')) c += 1;
            lst_1 = i;
        }
        if (i >= m && s[i - m] == '1') s[i] = '1';

        cout << r[i % m] + c << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    Long time, div.1 round :)
*/