#include <bits/stdc++.h>
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

const int N = 1e5 + 5;

int p[N];
int a, b, c, d;

bool check(int x) {
    p[1] = x;
    int cnt[4] = {a, b, c, d};
    --cnt[p[1]]; if(cnt[p[1]] == -1) return 0;
    for(register int i = 2; i <= a + b + c + d; i++) {
        if(p[i - 1] == 0) {
            p[i] = 1;
            --cnt[1];
            if(cnt[1] == -1) return 0;
            continue;
        }
        if(p[i - 1] == 1) {
            if(cnt[0]) {
                p[i] = 0;
            } else {
                p[i] = 2;
            }
            --cnt[p[i]];
            if(cnt[p[i]] == -1) return 0;
        }
        if(p[i - 1] == 2) {
            if(cnt[1]) {
                p[i] = 1;
            } else {
                p[i] = 3;
            }
            --cnt[p[i]];
            if(cnt[p[i]] == -1) return 0;
        }
        if(p[i - 1] == 3) {
            p[i] = 2;
            --cnt[2];
            if(cnt[2] == -1) return 0;
        }
    }
    return 1;
}

int main() {
    read(a); read(b); read(c); read(d);
    for(register int t = 0; t <= 3; t++) {
        if(check(t)) {
            printf("YES\n");
            for(register int i = 1; i <= a + b + c + d; i++) print(p[i], i == a + b + c + d ? '\n' : ' ');
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}