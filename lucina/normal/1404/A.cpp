#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k;
char s[nax];
int b[nax];

bool solve() {
    cin >> n >> k >> s;

    fill(b, b + k, -1);

    for (int i = 0 ; i < n ; ++ i) {
        if (s[i % k] == '?') {
            if (s[i] != '?') s[i % k] = s[i];
        } else {
            if (s[i] != '?' && s[i] != s[i % k]) return false;
        }
        if (s[i % k] != '?') b[i % k] = s[i % k] - '0';
    }

    int zero = 0;
    int one = 0;

    for (int i = 0 ; i < k ; ++ i) {
        if (b[i] == 1) ++ one;
        else if (b[i] == 0) ++ zero;
    }
    //cout << zero << ' ' << one << '\n';

    if (one <= k / 2 && zero <= k / 2) return true;
    else return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ;  T -- ;) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
/*
    Good Luck
        -Lucina
*/