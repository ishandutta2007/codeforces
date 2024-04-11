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


int n, m;
char s[120][120];
char s2[120][120];


int check(int n, int m) {
    if (n % 3 != 0) {
        return 0;
    }
    int d = n / 3;
    if (s[0][0] == s[d][0] || s[0][0] == s[2 * d][0] || s[d][0] == s[2 * d][0]) {
        return 0;
    }
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (s[i][j] != s[(i / d) * d][0])
                return 0;
    return 1;
}


int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        scanf(" %s", s[i]);
    if (check(n, m)) {
        cout << "YES\n";
    }
    else {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                s2[j][i] = s[i][j];
        swap(n, m);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                s[i][j] = s2[i][j];
        if (check(n, m)) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}