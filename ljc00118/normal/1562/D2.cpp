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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int N = 3e5 + 5;

vector <int> pos[N * 4];
char c[N];
int s[N];
int T, n, q;

int main() {
    read(T);
    while (T--) {
        read(n); read(q); scanf("%s", c + 1);
        for (int i = 1; i <= n; i++) {
            int x = (c[i] == '+' ? 1 : -1);
            if (i % 2 == 0) x = -x;
            s[i] = s[i - 1] + x;
        }
        for (int i = 0; i <= n * 4; i++) pos[i].clear();
        for (int i = 0; i < n; i++) pos[s[i] + s[i + 1] + n * 2].push_back(i);
        while (q--) {
            int l, r;
            read(l); read(r);
            if (s[r] - s[l - 1] == 0) print(0, '\n');
            else {
                if ((r - l + 1) & 1) print(1, '\n');
                else print(2, '\n'), print(r, ' '), --r;
                int tem = s[l - 1] + s[r] + 2 * n;
                int res = lower_bound(pos[tem].begin(), pos[tem].end(), l - 1) - pos[tem].begin();
                print(pos[tem][res] + 1, '\n');
            }
        }
    }
    return 0;
}