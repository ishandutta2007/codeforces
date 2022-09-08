#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 105;

char c[N][N], ans[N][N];
int T, n, m, cnt, ans1, ans2, cnt1, cnt2, k, x, y;

inline char getans(int x) {
    if(x <= 26) return x - 1 + 'a';
    if(x <= 52) return x - 26 - 1 + 'A';
    return x - 52 - 1 + '0';
}

inline void nxtxy() {
    if(x & 1) {
        if(y == m) {
            ++x;
        } else {
            ++y;
        }
    } else {
        if(y == 1) {
            ++x;
        } else {
            --y;
        }
    }
}

int main() {
    read(T);
    while(T--) {
        read(n); read(m); read(k); cnt = 0;
        for(register int i = 1; i <= n; i++) {
            scanf("%s", c[i] + 1);
            for(register int j = 1; j <= m; j++) {
                cnt += (c[i][j] == 'R');
            }
        }
        if(cnt % k == 0) {
            ans1 = ans2 = cnt / k;
            cnt1 = k; cnt2 = 0;
        } else {
            ans1 = cnt / k; ans2 = ans1 + 1;
            cnt2 = cnt % k; cnt1 = k - cnt % k;
        }
        x = 1; y = 1;
        for(register int i = 1; i <= cnt1; i++) {
            int now = 0;
            while(now != ans1) {
                ans[x][y] = getans(i);
                now += (c[x][y] == 'R');
                nxtxy();
            }
        }
        for(register int i = 1; i <= cnt2; i++) {
            int now = 0;
            while(now != ans2) {
                ans[x][y] = getans(i + cnt1);
                now += (c[x][y] == 'R');
                nxtxy();
            }
        }
        while(x != n + 1) {
            ans[x][y] = getans(cnt1 + cnt2);
            nxtxy();
        }
        for(register int i = 1; i <= n; i++) {
            for(register int j = 1; j <= m; j++) {
                putchar(ans[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}