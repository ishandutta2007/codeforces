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

const int N = 1e5 + 5, P = 998244353;

int n, fact[N], infact[N];

int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}
void inline factPrework(int n) {
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
    infact[n] = power(fact[n], P - 2);
    for (int i = n - 1; i; i--) infact[i] = infact[i + 1] * (i + 1ll) % P;
}
int inline C(int a, int b) {
    if (a < b || a < 0 || b < 0) return 0;
    return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

int z[2], c[2], o;
 
char op[5];

int o1 = 1, o2 = 1;

int main() {
    factPrework(1e5);
    read(n);
    for (int i = 1; i <= n; i++) {
        scanf("%s", op);
        if (op[0] == op[1] && op[0] == 'B') z[0]++;
        if (op[0] == op[1] && op[0] == 'W') z[1]++;
        if (op[0] == 'B') o1 = 0;
        if (op[1] == 'W') o1 = 0;
        
        if (op[0] == 'W') o2 = 0;
        if (op[1] == 'B') o2 = 0;

        if (op[0] != '?' && op[1] != '?') continue;
        if (op[0] == 'B' || op[1] == 'B') c[0]++;
        if (op[0] == 'W' || op[1] == 'W') c[1]++;
        if (op[0] == op[1] && op[0] == '?') c[0]++, c[1]++, o++;
    }
    
    int ans = 0;
    for (int i = 0; i <= c[0]; i++) {
        int k = (z[0] + i - z[1]);
        if (k < 0 || k > c[1]) continue;
        add(ans, 1ll * C(c[0], i) % P * C(c[1], k) % P);
    }
    if (!z[0] && !z[1]) {
        add(ans, P - power(2, o));
    }
    

    add(ans, o1 + o2);
    printf("%d\n", ans);
    return 0;
}