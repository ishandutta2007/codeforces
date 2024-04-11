#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

const int N = 1e6 + 5;

struct atom {
    int val, id;
    atom (int a = 0, int b = 0) : val(a), id(b) {}
};

bool operator < (const atom a, const atom b) {
    if (a.val != b.val) return a.val < b.val;
    return a.id > b.id;
}

map <ll, int> all;
atom dp[2][N];
ll a[3][N];
int nxt[3][N];
int n;

void upd(atom &x, atom y) { x = max(x, y); }

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[0][i]), a[0][i] += a[0][i - 1];
    for (int i = 1; i <= n; i++) read(a[1][i]), a[1][i] += a[1][i - 1];
    for (int i = 1; i <= n; i++) a[2][i] = a[0][i] + a[1][i];
    for (int i = 0; i <= 2; i++) {
        all.clear();
        int minn = n + 1;
        for (int j = n; j >= 0; j--) {
            if (all.count(a[i][j])) minn = min(minn, all[a[i][j]]);
            if (minn == n + 1) nxt[i][j] = -1;
            else nxt[i][j] = minn;
            all[a[i][j]] = j;
        }
    }
    dp[0][0] = dp[1][0] = atom(0, 0);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= 1; j++) {
            if (nxt[j ^ 1][dp[j][i].id] == i) {
                ++dp[j][i].val;
                dp[j][i].id = i;
            }
        }
        upd(dp[0][i], atom(dp[1][i].val, i));
        upd(dp[1][i], atom(dp[0][i].val, i));
        if (nxt[2][i] != -1) {
            upd(dp[0][nxt[2][i]], atom(dp[0][i].val + 1, nxt[2][i]));
            upd(dp[1][nxt[2][i]], atom(dp[1][i].val + 1, nxt[2][i]));
        }
        for (int j = 0; j <= 1; j++) {
            upd(dp[j][i + 1], dp[j][i]);
            if (nxt[j][i] != -1) upd(dp[j][nxt[j][i]], atom(dp[j][i].val + 1, dp[j][i].id));
            if (nxt[j ^ 1][dp[j][i].id] != -1) upd(dp[j ^ 1][nxt[j ^ 1][dp[j][i].id]], atom(dp[j][i].val + 1, i));
        }
    }
    print(dp[0][n].val, '\n');
    return 0;
}