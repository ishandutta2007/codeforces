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
 
const int N = 1e5 + 5, MAXN = 2e6 + 10;
 
char c[N];
vector <pii> f[N];
int a[N], ans[N], ss[N], len[N], pre[N];
int n, m;
 
void solve(int L, int R) {
    while (L < R && a[L] == 1) {
        ans[L] = 1;
        ++L;
    }
    while (L < R && a[R] == 1) {
        ans[R - 1] = 1;
        --R;
    }
    if (L >= R) return;
    int all = 1, tmp = 0;
    for (int i = L; i <= R; ) {
        ss[++tmp] = a[i];
        ++i;
        int nowlen = 0;
        while (a[i] == 1) {
            ++nowlen;
            ++i;
        }
        len[tmp] = nowlen;
        all = min(all * ss[tmp], MAXN);
    }
    if (all >= MAXN) {
        for (int i = L; i < R; i++) ans[i] = 2;
        return;
    }
    f[1].resize(1); f[1][0] = make_pair(0, ss[1]);
    for (int i = 1; i < tmp; i++) {
        int maxn = 0, mxid = -1;
        for (int j = 0; j < (int)f[i].size(); j++) {
            if (f[i][j].first + f[i][j].second > maxn) {
                maxn = f[i][j].first + f[i][j].second;
                mxid = j;
            }
        }
        assert(mxid != -1);
        pre[i + 1] = mxid;
        f[i + 1].resize(1); f[i + 1][0] = make_pair(maxn + len[i], ss[i + 1]);
        for (int j = 0; j < (int)f[i].size(); j++) {
            f[i + 1].push_back(make_pair(f[i][j].first, f[i][j].second * ss[i + 1]));
        }
        // for (int j = 0; j < (int)f[i].size(); j++) {
        //     fprintf(stderr, "i = %d, j = %d : {%d, %d}\n", i, j, f[i][j].first, f[i][j].second);
        // }
    }
    // for (int i = 1; i <= tmp; i++) fprintf(stderr, "{%d, %d}\n", ss[i], len[i]);
    int maxn = f[tmp][0].first + f[tmp][0].second, mxid = 0;
    for (int i = 1; i < (int)f[tmp].size(); i++) {
        int now = f[tmp][i].first + f[tmp][i].second;
        if (now > maxn) maxn = now, mxid = i;
    }
    for (int i = tmp, pos = R - 1; i >= 2; i--) {
        // fprintf(stderr, "pos = %d\n", pos);
        if (mxid == 0) {
            ans[pos] = 1; --pos;
            for (int j = 1; j <= len[i - 1]; j++) ans[pos] = 1, --pos;
            mxid = pre[i];
        } else {
            ans[pos] = 2; --pos;
            for (int j = 1; j <= len[i - 1]; j++) ans[pos] = 2, --pos;
            --mxid;
        }
    }
}
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    if (n == 1) {
        printf("%d\n", a[1]);
        return 0;
    }
    scanf("%s", c + 1); m = strlen(c + 1);
    sort(c + 1, c + m + 1);
    if (m == 1) {
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]);
            if (i != n) printf("%c", c[1]);
            else printf("\n");
        }
        return 0;
    }
    // *+-
    if (m == 2 && c[1] == '+' && c[2] == '-') {
        for (int i = 1; i <= n; i++) {
            printf("%d", a[i]);
            if (i != n) printf("+");
            else printf("\n");
        }
        return 0;
    }
    if (m == 2 && c[1] == '*' && c[2] == '-') {
        for (int i = 1, flag = (a[1] == 0); i <= n; i++) {
            printf("%d", a[i]);
            if (i == n) {
                printf("\n");
                return 0;
            }
            if (flag) printf("*");
            else if (a[i + 1] == 0) {
                flag = 1;
                printf("-");
            } else printf("*");
        }
    }
    int las = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            ans[i - 1] = ans[i] = 1;
            solve(las, i - 1);
            las = i + 1;
        }
    }
    solve(las, n);
    for (int i = 1; i <= n; i++) {
        printf("%d", a[i]);
        if (i != n) {
            if (ans[i] == 1) printf("+");
            else printf("*");
        } else printf("\n");
    }
    return 0;
}