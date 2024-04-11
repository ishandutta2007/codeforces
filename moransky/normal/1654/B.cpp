// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, c[26];

char s[N];

int main() {
    int T; read(T);
    while (T--) {
        scanf("%s", s + 1);
        memset(c, 0, sizeof c);
        n = strlen(s + 1);
        for (int i = 1; i <= n; i++) {
            c[s[i] - 'a']++;
        }
        int p = 1;
        while (c[s[p] - 'a'] > 1) {
            c[s[p] - 'a']--;
            p++;
        }
        for (int i = p; i <= n; i++) putchar(s[i]);
        puts("");
    }
    return 0;
}