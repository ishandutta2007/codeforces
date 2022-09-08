#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
 
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;
 
template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}
 
template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}
 
template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 5e5 + 5;

vector <int> pos[N * 2];
int sa[N], rk[N << 1], tp[N << 1], tax[N], height[N], s[N], st[N], r[N], id[N];
char c[N];
int n, m = 2, top; ll ans;

void radixSort() {
    for (int i = 1; i <= m; i++) tax[i] = 0;
    for (int i = 1; i <= n; i++) ++tax[rk[i]];
    for (int i = 2; i <= m; i++) tax[i] += tax[i - 1];
    for (int i = n; i >= 1; i--) sa[tax[rk[tp[i]]]--] = tp[i];
}

void suffixSort() {
    for (int i = 1; i <= n; i++) rk[i] = (c[i] == '(' ? 1 : 2), tp[i] = i;
    radixSort();
    for (int len = 1, p = 0; p < n; m = p, len <<= 1) {
        p = 0;
        for (int i = 1; i <= len; i++) tp[++p] = n - len + i;
        for (int i = 1; i <= n; i++) if (sa[i] > len) tp[++p] = sa[i] - len;
        radixSort(); swap(rk, tp); rk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++) rk[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] && tp[sa[i - 1] + len] == tp[sa[i] + len]) ? p : ++p;
    }
    int k = 0;
    for (int i = 1; i <= n; i++) {
        if (rk[i] == 1) { k = 0; continue; }
        int j = sa[rk[i] - 1];
        if (k) --k;
        while (i + k <= n && j + k <= n && c[i + k] == c[j + k]) ++k;
        height[rk[i]] = k;
    }
}

int main() {
    read(n); scanf("%s", c + 1); suffixSort();
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + (c[i] == '(' ? 1 : -1), pos[s[i] + n].push_back(i);
    s[n + 1] = -n - 1; st[++top] = n + 1;
    for (int i = n; i >= 0; i--) {
        while (s[st[top]] >= s[i]) --top;
        r[i] = st[top] - 1; st[++top] = i;
    }
    for (int i = 1; i <= n; i++) {
        if (i + height[rk[i]] > r[i - 1]) continue;
        int lid = lower_bound(pos[s[i - 1] + n].begin(), pos[s[i - 1] + n].end(), i + height[rk[i]]) - pos[s[i - 1] + n].begin();
        int rid = upper_bound(pos[s[i - 1] + n].begin(), pos[s[i - 1] + n].end(), r[i - 1]) - pos[s[i - 1] + n].begin();
        ans += rid - lid;
    }
    print(ans, '\n');
    return 0;
}