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

const int N = 1e5 + 5;

int n, q, ans;

char s[N], op[5];

int inline chk(int i) {
    if (i == 1 || i == n) return 0;
    if (s[i - 1] == 'a' && s[i] == 'b' && s[i + 1] == 'c') return 1;
    return 0;
}
 
int main() {
    read(n), read(q);
    scanf("%s", s + 1);
    for (int i = 2; i < n; i++) ans += chk(i);
    while (q--) {
        int i; read(i); scanf("%s", op);
        ans -= chk(i - 1);
        ans -= chk(i);
        ans -= chk(i + 1);
        s[i] = op[0];
        ans += chk(i - 1);
        ans += chk(i);
        ans += chk(i + 1);
        printf("%d\n", ans);
    }
    return 0;
}