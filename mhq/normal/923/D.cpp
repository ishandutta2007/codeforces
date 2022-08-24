#include <bits/stdc++.h>

using namespace std;
string s, t;
const int maxN = (int)1e5 + 10;
int sb[maxN];
int tb[maxN];
int SA[maxN];
int TA[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    srand(time(0));
    cin >> s >> t;
    for (int i  = 0; i < s.size(); i++) if (s[i] == 'C') s[i] = 'B';
    for (int i  = 0; i < t.size(); i++) if (t[i] == 'C') t[i] = 'B';
    sb[0] = (s[0] == 'B');
    tb[0] = (t[0] == 'B');
    for (int i = 1; i < s.size(); i++) {
        sb[i] = sb[i - 1] + (s[i] == 'B');
    }
    for (int i = 1; i < t.size(); i++) {
        tb[i] = tb[i - 1] + (t[i] == 'B');
    }
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            SA[i] = (s[i] == 'A');
            continue;
        }
        if (s[i] == 'A') SA[i] = SA[i - 1] + 1;
        else SA[i] = 0;
    }
    for (int i = 0; i < t.size(); i++) {
        if (i == 0) {
            TA[i] = (t[i] == 'A');
            continue;
        }
        if (t[i] == 'A') TA[i] = TA[i - 1] + 1;
        else TA[i] = 0;
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        int x, y, z, t;
        if (b != 0) x = sb[b] - sb[a - 1];
        else x = sb[b];
        y = min(SA[b], b - a + 1);
        if (c != 0) z = tb[d] - tb[c - 1];
        else z = tb[d];
        t = min(TA[d], d - c + 1);
        if (z < x) {
            cout << "0";
            continue;
        }
        if (x % 2 != z % 2) {
            cout << "0";
            continue;
        }
        if (x == 0 && z == 0) {
            if (y < t) {
                cout << "0";
                continue;
            }
            if (y % 3 != t % 3) {
                cout << "0";
                continue;
            }
            cout << "1";
            continue;
        }
        if (x == 0) {
            if (y < 1) {
                cout << "0";
                continue;
            }
            if (y - 1 < t) {
                cout << "0";
                continue;
            }
            cout << "1";
            continue;
        }
        if (x == z) {
            if (y < t) {
                cout << "0";
                continue;
            }
            if (y % 3 != t % 3) {
                cout << "0";
                continue;
            }
            cout << "1";
            continue;
        }
        if (y < t) {
            cout << "0";
            continue;
        }
        cout << "1";
    }
    return 0;
}