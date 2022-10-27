#include<bits/stdc++.h>
using namespace std;
const int nax = 4e5 + 10;
int a, b, ab, ba;
int n;
char s[nax];

bool solve() {
    cin >> a >> b >> ab >> ba;
    n = a + b + 2 * (ab + ba);
    int cnt_a = a + ab + ba, cnt_b = b + ab + ba;
    cin >> s;
    if (count(s, s + n, 'A') != cnt_a || count(s, s + n, 'B') != cnt_b)
        return false;

    vector <int> c[4];

    for (int i = 0 ; i + 1 < n ; ++ i) {
        if (s[i] != s[i + 1]) {
            int j = i;
            while (j + 1 < n && s[j] != s[j + 1]) j += 1;
            int l = j - i + 1;
            c[2 * (s[i] - 'A') + (l % 2)].push_back(l);
            i = j;
        }
    }
    for (int x = 0 ; x < 4 ; ++ x) sort(c[x].begin(), c[x].end(), greater<int>());
    reverse(c[2].begin(), c[2].end());
    int ex_ab = 0;

    for (int x = 0 ; x < 4 ; ++ x)
        if (x != 2) for (int j : c[x]) ex_ab += j / 2;
    for (int j : c[2]) ex_ab += (j - 2) / 2;
    if (ex_ab < ab) return false;

    int can_remove = ex_ab - ab;
    int ex_ba = 0;

    auto used = [&]()-> bool {
        if (can_remove) {
            ex_ba += 1;
            can_remove -= 1;
        }
        return ex_ba >= ba;
    };
    if (ex_ba >= ba) return true;

    for (int &j : c[2]) {

        bool all_remove = true;
        for (int k = 0 ; k < (j - 2) / 2 ; ++ k) {
            if (can_remove) ex_ba += 1, can_remove -= 1;
            else all_remove = false;
        }
        if (all_remove) ex_ba += 1;
        if (ex_ba >= ba) return true;
    }

    for (int j : c[3]) {
        for (int k = 0 ; k < j / 2 ; ++ k)
            if (used()) return true;
    }
    for (int j : c[1]) {
        for (int k = 0 ; k < j / 2 ; ++ k)
            if (used()) return true;
    }


    for (int j : c[0]) {
        int out = 0;
        for (int k = 0 ; k < j / 2 ; ++ k) {
            if (can_remove) out += 1, can_remove -= 1;
        }
        ex_ba += out - 1;
        if (ex_ba >= ba) return true;
    }

    return false;

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }

}