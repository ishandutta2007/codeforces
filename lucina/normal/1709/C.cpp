#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
string s;

bool solve() {
    cin >> s;
    int n = s.size();
    int q = 0, x = 0, y = 0;
    vector <int> where;

    for (int i = 0 ; i < n ; ++ i) {
        if (s[i] == '?') q += 1, where.push_back(i);
        else if (s[i] == '(') {
                    x += 1;
        } else y += 1;
    }
    //x + c == y + (q - c)
    //2 * c = y - x + q
    int c = (y - x + q) / 2;
    int d = q - c;
    string t = s;
    if (c == 0 || d == 0) return true;
    for (int j = 0 ; j < c ; ++ j) {
        t[where[j]] = '(';
    }
    for (int j = 0 ; j < d ; ++ j) {
        t[where[c + j]] = ')';
    }
    swap(t[where[c - 1]], t[where[c]]);
    int bal = 0;
    for (char cc : t) {
        bal += cc == '(' ? 1 : -1;
        if (bal < 0) return true;
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/*
    Eduroundd
*/