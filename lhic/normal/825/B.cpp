#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

string s[10];

int ch(char a, char b, char c, char d, char e) {
    if (a == b && b == c && d == c && e == d && c == 'X')
        return 1;
    return 0;
}

int check() {
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j) {
            if (i + 5 <= 10 && ch(s[i][j], s[i + 1][j], s[i + 2][j], s[i + 3][j], s[i + 4][j])) {
                return 1;
            }
            if (j + 5 <= 10 && ch(s[i][j], s[i][j + 1], s[i][j + 2], s[i][j + 3], s[i][j + 4])) {
                return 1;
            }
            if (i + 5 <= 10 && j + 5 <= 10 && ch(s[i][j], s[i + 1][j + 1], s[i + 2][j + 2], s[i + 3][j + 3], s[i + 4][j + 4])) {
                return 1;
            }
            if (i + 5 <= 10 && j >= 4 && ch(s[i][j], s[i + 1][j - 1], s[i + 2][j - 2], s[i + 3][j - 3], s[i + 4][j - 4])) {
                return 1;
            }
        }
    return 0;
}

int main() {
    for (int i = 0; i < 10; ++i)
        cin >> s[i];
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < 10; ++j) {
            if (s[i][j] != '.')
                continue;
            s[i][j] = 'X';
            if (check()) {
                cout << "YES\n";
                return 0;
            }
            s[i][j] = '.';
        }
    cout << "NO\n";
    return 0;
}