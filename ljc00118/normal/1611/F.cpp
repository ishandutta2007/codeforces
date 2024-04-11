#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
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

ll sum[N];
int a[N], st[N];
int T, n, top, ansl, ansr; ll s;

int main() {
    read(T);
    while (T--) {
        read(n); read(s);
        ansl = 1; ansr = 0;
        for (int i = 1; i <= n; i++) {
            read(a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        top = 0; st[0] = n + 1;
        for (int i = n; i >= 1; i--) {
            while (top && sum[st[top]] >= sum[i]) --top;
            st[++top] = i;
            if (a[i] + s < 0) continue;
            int l = 1, r = top, ans = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (sum[st[mid]] - sum[i - 1] + s >= 0) r = mid - 1, ans = st[mid - 1] - 1;
                else l = mid + 1;
            }
            if (ans - i > ansr - ansl) {
                ansl = i;
                ansr = ans;
            }
        }
        if (!ansr) puts("-1");
        else print(ansl, ' '), print(ansr, '\n');
    }
    return 0;
}