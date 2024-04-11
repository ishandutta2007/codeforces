#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 33;

int n, k;
int a, b;
int f[MAXN][MAXN][MAXN][2];

int rec(int k, int a, int b, int c) {
    if (f[k][a][b][c] != -1) {
        return f[k][a][b][c];
    }
    if (k > a + b) {
        f[k][a][b][c] = 2;
        return 2;
    }

    if (k == 0) {
        if (a % 2 == 0) {
            f[k][a][b][c] = 1;
        } else {
            f[k][a][b][c] = 0;
        }

        return f[k][a][b][c];
    }

    if (a > 0) {
        int d = rec(k - 1, a - 1, b, c ^ 1);
        if (d == c) {
            f[k][a][b][c] = c;
            return c;
        }
    }

    if (b > 0) {
        int d = rec(k - 1, a, b - 1, c ^ 1);
        if (d == c) {
            f[k][a][b][c] = c;
            return c;
        }
    }

    f[k][a][b][c] = c ^ 1;
    return c ^ 1;
}

int get_result(int k, int a, int b) {
    if (k > a + b) {
        return 2;
    }

    if (k == 0) {
        if (a % 2 == 0) {
            return 1;
        } else {
            return 0;
        }
    }

    if (a <= (k - 1) / 2) {
        return 1;
    }

    if (b >= (k + 2) / 2) {
        if (k % 2 == 0) {
            return 1;
        }
        return 0;
    }
    
    if ( (a + b) % 2 != k % 2 ) {
        return 0;
    } 
    return 1;
}

void preprocess() {
    memset(f, -1, sizeof(f) );

    for (int k = 0; k <= 20; k++) {
        cerr << "K = " << k << "\n\n";

        for (int i = 0; i <= 30; i++) {
            for (int j = 0; j <= 30; j++) {
                cerr << (rec(k, i, j, 0) ^ get_result(k, i, j)) << " ";
            }
            cerr << "\n";
        }

        cerr << "\n";
    }
}

void solve() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if (x % 2) {
            a += 1;
        } else {
            b += 1;
        }
    }

    k = n - k;

    cout << (get_result(k, a, b) == 0 ? "Stannis" : "Daenerys") << "\n";
}

int main() {
    // preprocess();
	int cases; cases = 1;
	for (int i = 0; i < cases; i++) {
        solve();
    }
    return 0;
}