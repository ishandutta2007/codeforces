// Skyqwq
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 5e3 + 5;

int n;

char s[N << 1];
 
bool inline check(int k) {
    bool o = 0;
    for (int i = 1; i <= n; i++)
        if (s[i + k] != s[i]) o = 1;
    if (!o) return 0;
    for (int i = 1; i <= n / 2; i++) {
        if (s[i + k] != s[n - i + 1 + k]) return 0;
    }
    return 1;
}

int main() {
    scanf("%s", s + 1); n = strlen(s + 1);
    bool o = 0;
    for (int i = 1; i <= n / 2; i++) {
        if (s[i] != s[1] || s[n - i + 1] != s[1]) o = 1;
    }
    if (!o) { puts("Impossible"); return 0; }
    for (int i = 1; i <= n; i++) s[i + n] = s[i];
    for (int i = 0; i < n; i++) 
        if (check(i)) { puts("1"); return 0; }
    puts("2");
	return 0;
}