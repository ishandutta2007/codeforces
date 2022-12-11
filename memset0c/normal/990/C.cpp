// =================================
//   author: memset0
//   date: 2018.12.04 19:53:15
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
        while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
        if (f) x = -x;
    }

    template < class T >
    inline void print(T x) {
        if (x < 0) putchar('-'), x = -x;
        if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
    print(x), putchar(c);
}

const int N = 3e5 + 10;
int n, m, top, flag;
ll ans;
int a[N], stk[N], cnt[N], cnt2[N];
char s[N];

void main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1), m = strlen(s + 1);
        top = 0;
        for (int i = 1; i <= m; i++)
            if (s[i] == '(') {
                stk[++top] = s[i];
            } else {
                if (top && stk[top] == '(') top--;
                else stk[++top] = s[i];
            }
        flag = true;
        for (int i = 1; i <= top; i++)
            if (stk[i] != stk[1]) {
                flag = false;
                break;
            }
        // printf("%d %d : ", flag, top);
        // for (int i = 1; i <= top; i++)
        //     putchar(stk[i]);
        // putchar('\n');  
        if (!flag) continue;
        if (!top) ++cnt[0], ++cnt2[0];
        else if (stk[1] == '(') ++cnt[top];
        else ++cnt2[top];
    }
    for (int i = 0; i < N; i++)
        ans += (ll)cnt[i] * cnt2[i];
    print(ans, '\n');
}

} signed main() { return ringo::main(), 0; }

/*
10
()()(
)((
)()(((()(
(((()(
)(()((
))
()()()()
))()))((
)
))())(
*/