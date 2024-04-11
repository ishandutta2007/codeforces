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

int cnt[26][26], cnta[26], cntb[26];
char c[15];
int T, n; ll ans;

int main() {
    read(T);
    while (T--) {
        ans = 0;
        memset(cnt, 0, sizeof(cnt));
        memset(cnta, 0, sizeof(cnta));
        memset(cntb, 0, sizeof(cntb));
        read(n);
        for (int i = 1; i <= n; i++) {
            scanf("%s", c + 1);
            ++cnt[c[1] - 'a'][c[2] - 'a'];
            ++cnta[c[1] - 'a'];
            ++cntb[c[2] - 'a'];
        }
        for (int i = 0; i < 26; i++) {
            ans += 1ll * cnta[i] * (cnta[i] - 1) / 2;
            ans += 1ll * cntb[i] * (cntb[i] - 1) / 2;
            for (int j = 0; j < 26; j++) {
                ans -= 1ll * cnt[i][j] * (cnt[i][j] - 1);
            }
        }
        print(ans, '\n');
    }
    return 0;
}