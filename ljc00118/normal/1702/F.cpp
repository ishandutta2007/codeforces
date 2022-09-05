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

const int N = 2e5 + 5;

queue <int> q1, q2;
int a[N], b[N];
int T, n, ans;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            while (a[i] % 2 == 0) a[i] /= 2;
        }
        for (int i = 1; i <= n; i++) {
            read(b[i]);
            while (b[i] < 1000000000) b[i] *= 2;
        }
        while (!q1.empty()) q1.pop();
        while (!q2.empty()) q2.pop();
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        for (int i = n; i >= 1; i--) q1.push(b[i]);
        ans = 1;
        for (int i = n; i >= 1; i--) {
            while (1) {
                int v1 = -1, v2 = 1, val;
                if (!q1.empty()) v1 = q1.front();
                if (!q2.empty()) v2 = q2.front();
                if (v1 > v2) val = v1, q1.pop();
                else val = v2, q2.pop();
                if (val == a[i]) break;
                if (val < a[i]) {
                    fprintf(stderr, "i = %d, val = %d, a[i] = %d\n", i, val, a[i]);
                    ans = 0;
                    break;
                }
                q2.push(val / 2);
            }
            if (!ans) break;
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}