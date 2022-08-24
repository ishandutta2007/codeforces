#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

int n, m;
char s[1200][1200];

void st(int x, int y, int fl[1200][1200]) {
    for (int i = 0; x + i < n; ++i) {
        if (s[x + i][y] == '*')
            break;
        fl[x + i][y] = 1;
    }
    for (int i = 0; x - i >= 0; ++i) {
        if (s[x - i][y] == '*')
            break;
        fl[x - i][y] = 1;
    }
    for (int i = 0; y + i < m; ++i) {
        if (s[x][y + i] == '*')
            break;
        fl[x][y + i] = 1;
    }
    for (int i = 0; y - i >= 0; ++i) {
        if (s[x][y - i] == '*')
            break;
        fl[x][y - i] = 1;
    }
}


int fl1[1200][1200];
int fl2[1200][1200];

int ch(int x, int y) {
    for (int i = 0; x + i < n; ++i) {
        if (s[x + i][y] == '*')
            break;
        if (fl2[x + i][y])
            return 1;
    }
    for (int i = 0; x - i >= 0; ++i) {
        if (s[x - i][y] == '*')
            break;
        if (fl2[x - i][y])
            return 1;
    }
    for (int i = 0; y + i < m; ++i) {
        if (s[x][y + i] == '*')
            break;
        if (fl2[x][y + i])
            return 1;
    }
    for (int i = 0; y - i >= 0; ++i) {
        if (s[x][y - i] == '*')
            break;
        if (fl2[x][y - i])
            return 1;
    }
    return 0;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf(" %s", s[i]);
    int sx = 0, sy = 0;
    int ex = 0, ey = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (s[i][j] == 'S')
                sx = i, sy = j;
            if (s[i][j] == 'T')
                ex = i, ey = j;
        }
    st(sx, sy, fl1);
    st(ex, ey, fl2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (fl1[i][j]) {
                if (ch(i, j)) {
                    cout << "YES\n";
                    return 0;
                }
            }
        }
    }
    cout << "NO\n";
	return 0;
}