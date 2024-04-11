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

int A, B, C, D, n;

char s[N];

int t1, t2, h1[N], h2[N];

bool inline chk() {
    t1 = t2 = 0;
    int c[2] = { 0, 0 };
    for (int i = 1; i <= n; i++) c[s[i] - 'A']++;
    if (c[0] != A + C + D || c[1] != B + C + D) return 0;
    int fr = 0, ga = 0, gb = 0;
    for (int i = 1; i <= n; i++) {
        if (i == n || s[i] == s[i + 1]) continue;
        int j = i;
        while (j < n && s[j + 1] != s[j]) {
            j++;
        }
        int t = j - i + 1;
        int l = j - i + 1;
        if (l & 1) fr += l / 2;
        else {
            if (s[i] == 'A') h1[++t1] = l / 2 - 1;
            else h2[++t2] = l / 2 - 1;
        }
        i = j;
    }
    sort(h1 + 1, h1 + 1 + t1);
    sort(h2 + 1, h2 + 1 + t2);
    int u = 1;
    while (u <= t1 && ga + h1[u] < C) {
        ga += h1[u] + 1;
        u++;
    }
    while (u <= t1) {
        fr += h1[u++];
    }
    u = 1;
    while (u <= t2 && gb + h2[u] < D) {
        gb += h2[u] + 1;
        u++;
    }
    while (u <= t2) {
        fr += h2[u++];
    }
    int nd = 0;
    if (ga < C) nd += C - ga;
    if (gb < D) nd += D - gb;
    return fr >= nd;
}

int main() {
    int T; read(T);
    while (T--) {
        read(A), read(B), read(C), read(D);
        scanf("%s", s + 1); n = strlen(s + 1);
        puts(chk() ? "YES" : "NO");
    }
    return 0;
}