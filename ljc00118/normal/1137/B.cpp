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

const int N = 500005;

char s[N], t[N];
int nxt[N], cnt0, cnt1;
int len1, len2;

int main() {
    scanf("%s", s + 1); scanf("%s", t + 1);
    len1 = strlen(s + 1); len2 = strlen(t + 1);
    for(register int i = 1; i <= len1; i++) {
        if(s[i] == '0') ++cnt0;
        if(s[i] == '1') ++cnt1;
    }
    nxt[1] = 0;
    for(register int i = 1; i < len2; i++) {
        int k = nxt[i];
        while(k && t[k + 1] != t[i + 1]) k = nxt[k];
        if(t[k + 1] == t[i + 1]) ++k;
        nxt[i + 1] = k;
    }
    int ans1 = 0, ans2 = 0, Ans1 = 0, Ans2 = 0;
    for(register int i = 1; i <= len2; i++) {
        if(t[i] == '0') ++ans1;
        else ++ans2;
    }
    for(register int i = nxt[len2] + 1; i <= len2; i++) {
        if(t[i] == '0') ++Ans1;
        else ++Ans2;
    }
    if(ans1 > cnt0 || ans2 > cnt1) {
        for(register int i = 1; i <= cnt0; i++) putchar('0');
        for(register int i = 1; i <= cnt1; i++) putchar('1');
        return 0;
    }
    cnt0 -= ans1; cnt1 -= ans2;
    for(register int i = 1; i <= len2; i++) putchar(t[i]);
    while(cnt0 >= Ans1 && cnt1 >= Ans2) {
        cnt0 -= Ans1; cnt1 -= Ans2;
        for(register int i = nxt[len2] + 1; i <= len2; i++) putchar(t[i]);
    }
    for(register int i = 1; i <= cnt0; i++) putchar('0');
    for(register int i = 1; i <= cnt1; i++) putchar('1');
    return 0;
} //