#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 2e5 + 5, INF = 0x3fffffff;

const char s[3] = {'o', 'n', 'e'}, t[3] = {'t', 'w', 'o'};

vector <int> ans;
char c[N];
int f[N][3][3];
int T, n;

int main() {
    read(T);
    while (T--) {
        scanf("%s", c + 1); n = strlen(c + 1);
        ans.clear();
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                f[0][i][j] = INF;
            }
        }
        f[0][0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 2; k++) {
                    f[i][j][k] = INF;
                }
            }
            for (int j = 0; j <= 2; j++) {
                for (int k = 0; k <= 2; k++) {
                    int goj = (c[i] == s[j] ? j + 1 : 0);
                    int gok = (c[i] == t[k] ? k + 1 : 0);
                    if (c[i] == s[0]) goj = 1;
                    if (c[i] == t[0]) gok = 1;
                    if(goj != 3 && gok != 3) f[i][goj][gok] = min(f[i][goj][gok], f[i - 1][j][k]);
                    f[i][j][k] = min(f[i][j][k], f[i - 1][j][k] + 1);
                    // fprintf(stderr, "f[%d][%d][%d] = %d\n", i - 1, j, k, f[i - 1][j][k]);
                }
            }
        }
        int i = n, x = 0, y = 0;
        for (int i = 0; i <= 2; i++) {
            for (int j = 0; j <= 2; j++) {
                if (f[n][i][j] < f[n][x][y]) {
                    x = i; y = j;
                }
            }
        }
        while (i) {
            // fprintf(stderr, "i = %d, x = %d, y = %d\n", i, x, y);
            bool ok = 0;
            for (int j = 0; j <= 2; j++) {
                if (ok) break;
                for (int k = 0; k <= 2; k++) {
                    int goj = (c[i] == s[j] ? j + 1 : 0);
                    int gok = (c[i] == t[k] ? k + 1 : 0);
                    if (c[i] == s[0]) goj = 1;
                    if (c[i] == t[0]) gok = 1;
                    if(goj == x && gok == y && f[i - 1][j][k] == f[i][x][y]) {
                        x = j; y = k; --i;
                        ok = 1; break;
                    }
                }
            }
            if (!ok) {
                --i;
                ans.push_back(i + 1);
            }
        }
        print((int)ans.size(), '\n');
        for (int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
        putchar('\n');
    }
    return 0;
}