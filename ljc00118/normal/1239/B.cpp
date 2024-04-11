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

const int N = 3e5 + 5;

char c[N];
int s[N], s1[N], s2[N], s3[N];
int n, minn, ans, ans1 = 1, ans2 = 1;

int main() {
    read(n); scanf("%s", c + 1);
    for(register int i = 1; i <= n; i++) s[i] = s[i - 1] + (c[i] == '(' ? 1 : -1);
    if(s[n]) { print(0, '\n'); print(1, ' '); print(1, '\n'); return 0; }
    for(register int i = 1; i <= n; i++) {
        if(s[i] < minn) {
            minn = s[i];
            ans = 1;
        } else if(s[i] == minn) ++ans;
    }
    for(register int i = 1; i <= n; i++) {
        s1[i] = s1[i - 1] + (s[i] == minn);
        s2[i] = s2[i - 1] + (s[i] == minn + 1);
        s3[i] = s3[i - 1] + (s[i] == minn + 2);
    }
    // minn -> minn + 2
    if(minn <= -2) {
        int l = -1, r = -1;
        for(register int i = 1; i <= n; i++) if(s[i] <= minn + 1) { l = i; break; }
        for(register int i = n; i >= 1; i--) if(s[i] <= minn + 1) { r = i + 1; break; }
        if(r != n + 1) {
            int val = s1[n] + s3[l - 1] + s3[n] - s3[r - 1];
            if(val > ans) ans = val, ans1 = l, ans2 = r;
        }
    }
    // minn -> minn + 1
    if(minn <= -1) {
        int l = -1, r = -1;
        for(register int i = 1; i <= n; i++) if(s[i] == minn) { l = i; break; }
        for(register int i = n; i >= 1; i--) if(s[i] == minn) { r = i + 1; break; }
        if(r != n + 1) {
            int val = s2[l - 1] + s2[n] - s2[r - 1];
            if(val > ans) ans = val, ans1 = l, ans2 = r;
        }
    }
    // minn -> minn
    for(register int l = 1, r; l < n; l = r + 1) {
        if(s[l] <= minn + 1) { r = l; continue; }
        int L = -1, R = -1;
        if(c[l] == '(') L = l;
        if(c[l + 1] == ')') R = l + 1;
        r = l;
        while(r < n - 1 && s[r + 1] > minn + 1) {
            ++r;
            if(L == -1 && c[r] == '(') L = r;
            if(c[r + 1] == ')') R = r + 1;
        }
        if(L != -1 && R != -1 && L < R) {
            int val = s1[n] + s3[R - 1] - s3[L - 1];
            if(val > ans) ans = val, ans1 = L, ans2 = R;
        }
    }
    // minn -> minn - 1
    for(register int l = 1, r; l < n; l = r + 1) {
        if(s[l] == minn) { r = l; continue; }
        int L = -1, R = -1;
        if(c[l] == '(') L = l;
        if(c[l + 1] == ')') R = l + 1;
        r = l;
        while(r < n - 1 && s[r + 1] > minn) {
            ++r;
            if(L == -1 && c[r] == '(') L = r;
            if(c[r + 1] == ')') R = r + 1;
        }
        if(L != -1 && R != -1 && L < R) {
            int val = s2[R - 1] - s2[L - 1];
            if(val > ans) ans = val, ans1 = L, ans2 = R;
        }   
    }
    print(ans, '\n'), print(ans1, ' '), print(ans2, '\n');
    return 0;
}