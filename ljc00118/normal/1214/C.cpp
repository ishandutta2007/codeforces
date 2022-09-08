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

const int N = 2e5 + 5;

char c[N];
int n, cnt[2], a, b, tot, ok;

int main() {
    read(n); scanf("%s", c + 1);
    if(n & 1) { printf("No\n"); return 0; }
    for(register int i = 1; i <= n; i++) {
        int now = 0;
        if(c[i] == ')') now = 1;
        ++cnt[now];
    }
    if(cnt[0] != cnt[1]) { printf("No\n"); return 0; }
    a = 1; while(c[a] != ')') ++a;
    b = n; while(c[b] != '(') --b;
    if(a > b) { printf("Yes\n"); return 0; }
    // swap(c[a], c[b]);
    c[a] = '?'; ok = 1;
    for(register int i = 1; i <= n; i++) {
        if(c[i] == '(') ++tot;
        if(c[i] == ')') {
            if(!tot) {
                ok = 0;
                break;
            }
            --tot;
        }
    }
    if(ok) { printf("Yes\n"); return 0; }
    c[a] = ')'; c[b] = '?'; tot = ok = 1;
    for(register int i = 1; i <= n; i++) {
        if(c[i] == '(') ++tot;
        if(c[i] == ')') {
            if(!tot) {
                ok = 0;
                break;
            }
            --tot;
        }
    }
    if(ok) printf("Yes\n");
    else printf("No\n");
    return 0;
}