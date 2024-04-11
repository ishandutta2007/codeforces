#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

const int N = 2e6 + 5;

int ch[N][26], len[N], fa[N], a[N], tax[N], siz[N], vis[N], last = 1, cnt = 1;
char c[N]; int n, t;

void extend(int x) {
    int p = last, np = last = ++cnt; len[np] = len[p] + 1;
    for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = np;
    if(!p) fa[np] = 1;
    else {
        int q = ch[p][x];
        if(len[q] == len[p] + 1) fa[np] = q;
        else {
            int nq = ++cnt; len[nq] = len[p] + 1;
            memcpy(ch[nq], ch[q], sizeof(ch[nq]));
            fa[nq] = fa[q]; fa[q] = fa[np] = nq;
            for(; ch[p][x] == q; p = fa[p]) ch[p][x] = nq;
        }
    }
    siz[np] = 1;
}

void topsort() {
    for(register int i = 1; i <= cnt; i++) ++tax[len[i]];
    for(register int i = 1; i <= cnt; i++) tax[i] += tax[i - 1];
    for(register int i = 1; i <= cnt; i++) a[tax[len[i]]--] = i;
}

int main() {
    scanf("%s", c + 1); n = strlen(c + 1);
    for(register int i = 1; i <= n; i++) extend(c[i] - 'a');
    topsort();
    for(register int i = cnt; i >= 1; i--) siz[fa[a[i]]] += siz[a[i]];
    // fprintf(stderr, "ch[1][0] = %d, siz[ch[1][0]] = %d\n", ch[1][0], siz[ch[1][0]]);
    read(t); for(register int i = 1; i <= t; i++) {
        scanf("%s", c + 1); n = strlen(c + 1);
        for(register int j = n + 1; j <= (n << 1); j++) c[j] = c[j - n];
        int now = 1, len = 0, ans = 0;
        for(register int j = 1; j <= (n << 1); j++) {
            int x = c[j] - 'a';
            while(now && !ch[now][x]) now = fa[now], len = ::len[now];
            if(now) now = ch[now][x], ++len;
            else now = 1, len = 0;
            if(len >= n) {
                while(::len[fa[now]] >= n) now = fa[now], len = ::len[now];
                if(vis[now] != i) vis[now] = i, ans += siz[now];
            }
        }
        print(ans, '\n');
    }
    return 0;
}