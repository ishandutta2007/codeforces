// Skyqwq
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
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

const int N = 3e5 + 5;

int n, m, ans = 2e9, A[N], B[N];

char c[4] = { 'A', 'G', 'C', 'T' };

char s[N];

vector<char> g[N];
vector<char> ret[N];
 
void inline work() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int t = (i & 1) * 2;
        int s1 = 0, s0 = 0;
        for (int j = 1; j <= m; j++) {
            s1 += g[i][j] != c[t + (j & 1)];
            s0 += g[i][j] != c[t + !(j & 1)];
        }
        A[i] = s0 <= s1 ? 0 : 1;
        res += min(s1, s0);
    }
    int r2 = 0;
    for (int i = 1; i <= m; i++) {
        int t = (i & 1) * 2;
        int s1 = 0, s0 = 0;
        for (int j = 1; j <= n; j++) {
            s1 += g[j][i] != c[t + (j & 1)];
            s0 += g[j][i] != c[t + !(j & 1)];
        }
        B[i] = s0 <= s1 ? 0 : 1;
        r2 += min(s1, s0);
    }

    int t = min(r2, res);
    if (t < ans) {
        ans = t;
        if (t == res) {
            for (int i = 1; i <= n; i++) {
                int t = (i & 1) * 2;
                for (int j = 1; j <= m; j++) {
                    char o = A[i] ? c[t + (j & 1)] : c[t + !(j & 1)];
                    ret[i][j] = o;
                }
            }
        } else {
            for (int i = 1; i <= m; i++) {
                int t = (i & 1) * 2;
                for (int j = 1; j <= n; j++) {
                    char o = B[i] ? c[t + (j & 1)] : c[t + !(j & 1)];
                    ret[j][i] = o;
                }
            }
        }
    }
}

int main() {
    read(n), read(m); 
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        g[i].resize(m + 1);
        ret[i].resize(m + 1);
        for (int j = 1; j <= m; j++) g[i][j] = s[j];
    }
    do {
        work();
    } while (next_permutation(c, c + 4));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) putchar(ret[i][j]);
        puts("");
    }
	return 0;
}