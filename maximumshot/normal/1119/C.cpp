#include <bits/stdc++.h>

// pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace __gnu_pbds;
// gp_hash_table<int, int> table;

using namespace std;

typedef unsigned long long ull;
typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;
typedef pair<long double, long double> pdd;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1e18;

const int N = 505;

void transpose(int n, int m, int **a, int **buff) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            buff[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = buff[i][j];
        }
    }
}

int n, m;
int a[N][N];
int b[N][N];
int buff[N][N];

const char *NO = "No";
const char *YES = "Yes";

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if(i) a[i - 1][j] ^= a[i][j];
            if(j) a[i][j - 1] ^= a[i][j];
            if(i && j) a[i - 1][j - 1] ^= a[i][j];

            if(i) b[i - 1][j] ^= b[i][j];
            if(j) b[i][j - 1] ^= b[i][j];
            if(i && j) b[i - 1][j - 1] ^= b[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i][0] != b[i][0]) {
            puts(NO);
            return 0;
        }
    }

    for (int i = 0; i < m; i++) {
        if(a[0][i] != b[0][i]) {
            puts(NO);
            return 0;
        }
    }

    puts(YES);

    return 0;
}