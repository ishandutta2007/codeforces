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
 
const int N = 1e6 + 5;
 
int nxt[N];
char ans[N], c[N];
int n, len, ansLen;
 
int main() {
    read(n);
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c + 1); len = strlen(c + 1);
        int minn = min(ansLen, len), top = len; c[++top] = '#';
        for(register int j = ansLen - minn + 1; j <= ansLen; j++) c[++top] = ans[j];
        nxt[0] = nxt[1] = 0;
        for(register int j = 1; j < top; j++) {
            int k = nxt[j];
            while(k && c[k + 1] != c[j + 1]) k = nxt[k];
            if(c[k + 1] == c[j + 1]) ++k;
            nxt[j + 1] = k;
        }
        for(register int j = nxt[top] + 1; j <= len; j++) ans[++ansLen] = c[j];
    }
    for(register int i = 1; i <= ansLen; i++) putchar(ans[i]);
    putchar('\n');
    return 0;
}