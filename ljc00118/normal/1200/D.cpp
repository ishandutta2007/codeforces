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
 
const int N = 2005;
 
char c[N][N];
int s[N][N], a[N][N];
int n, k, ans, maxn;
 
int main() {
    read(n); read(k);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c[i] + 1);
        for(register int j = 1; j <= n; j++) {
            a[i][j] = c[i][j] == 'W' ? 0 : 1;
        }
    }
    for(register int i = 1; i <= n; i++) {
        int L = 0, R = 0;
        for(register int j = 1; j <= n; j++) if(a[i][j]) { L = j; break; }
        for(register int j = n; j >= 1; j--) if(a[i][j]) { R = j; break; }
        if(!L) { ++ans; continue; }
        if(R - L + 1 <= k) {
            ++s[max(1, i - k + 1)][max(1, R - k + 1)];
            --s[max(1, i - k + 1)][L + 1];
            --s[i + 1][max(1, R - k + 1)];
            ++s[i + 1][L + 1];
        }
    }
    for(register int j = 1; j <= n; j++) {
        int L = 0, R = 0;
        for(register int i = 1; i <= n; i++) if(a[i][j]) { L = i; break; }
        for(register int i = n; i >= 1; i--) if(a[i][j]) { R = i; break; }
        if(!L) { ++ans; continue; }
        if(R - L + 1 <= k) {
            ++s[max(1, R - k + 1)][max(1, j - k + 1)];
            --s[L + 1][max(1, j - k + 1)];
            --s[max(1, R - k + 1)][j + 1];
            ++s[L + 1][j + 1];
        }
    }
    for(register int i = 1; i <= n - k + 1; i++) {
        for(register int j = 1; j <= n - k + 1; j++) {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            maxn = max(maxn, s[i][j]);
        }
    }
    print(maxn + ans, '\n');
    return 0;
}