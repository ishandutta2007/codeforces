// =================================
//   author: memset0
//   date: 2019.03.08 17:18:45
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 500005;

char s[N], t[N];
int n, m, f, g, ans1, ans2, cnt0, cnt1, nxt[N];

void main() {
    scanf("%s", s + 1); scanf("%s", t + 1), n = strlen(s + 1); m = strlen(t + 1);
    for (int i = 1; i <= n; i++) {
		cnt0 += s[i] == '0';
		cnt1 += s[i] == '1';
    }
    nxt[1] = 0;
    for (int i = 1; i < m; i++) {
        int k = nxt[i];
        while(k && t[k + 1] != t[i + 1]) k = nxt[k];
        if(t[k + 1] == t[i + 1]) ++k;
        nxt[i + 1] = k;
    }
    for (int i = 1; i <= m; i++) (t[i] == '0') ? ++f : ++g;
    for (int i = nxt[m] + 1; i <= m; i++) (t[i] == '0') ? ++ans1 : ++ans2;
    if (f > cnt0 || g > cnt1) {
        for (int i = 1; i <= cnt0; i++) putchar('0');
        for (int i = 1; i <= cnt1; i++) putchar('1');
        putchar('\n'); return;
    }
    cnt0 -= f; cnt1 -= g;
    for (int i = 1; i <= m; i++) putchar(t[i]);
    while (cnt0 >= ans1 && cnt1 >= ans2) {
        cnt0 -= ans1; cnt1 -= ans2;
        for (int i = nxt[m] + 1; i <= m; i++) putchar(t[i]);
    }
    for (int i = 1; i <= cnt0; i++) putchar('0');
    for (int i = 1; i <= cnt1; i++) putchar('1');
    putchar('\n'); return;
}

} signed main() { return ringo::main(), 0; }