#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
 
const int N = 2e5 + 5, sqr = 100;
 
char c[N];
ll qwq[N], qaq[N];
int nxt[N], s[N];
int n; ll ans;
 
int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    // srand(time(0));
    // n = 200000;
    // for (int i = 1; i <= n; i++) c[i] = (rand() & 1) + '0';
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (c[i] == '1'), qwq[i] = -i;
    nxt[n] = -1;
    for (int i = n - 1; i >= 1; i--) {
        if (c[i + 1] == '1') nxt[i] = i + 1;
        else nxt[i] = nxt[i + 1];
    }
    for (int i = 1; i <= n; i++) {
        int now = (c[i] == '1' ? i : nxt[i]);
        for (int j = 1; j <= N / sqr + 1 && ~now; j++, now = nxt[now]) {
            int l = max(sqr + 1, (now - i) / j + 1), r = ((nxt[now] == -1 ? n : nxt[now] - 1) - i + 1) / j;
            if (l <= r) ans += (r - l + 1);
        }
    }
    for (int d = 1; d <= sqr; d++) {
        // fprintf(stderr, "d = %d\n", d);
        for (int i = 0; i <= n; i++) qwq[i] += s[i], qaq[i] = qwq[i];
        sort(qaq, qaq + n + 1);
        for (int l = 0, r; l <= n; l = r + 1) {
            r = l;
            while (r < n && qaq[l] == qaq[r + 1]) ++r;
            ans += 1ll * (r - l) * (r - l + 1) / 2;
        }
    }
    print(ans, '\n');
    return 0;
}