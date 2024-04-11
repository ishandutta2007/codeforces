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

int a[N];
int T, n; ll w;

int main() {
    read(T);
    while (T--) {
        read(n); read(w);
        for (int i = 1; i <= n; i++) read(a[i]);
        vector <int> pos;
        ll sum = 0;
        int cando = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] > w) continue;
            if (sum >= (w + 1) / 2) break;
            if (sum + a[i] > w) {
                cando = 1;
                print(1, '\n');
                print(i, '\n');
                break;
            }
            sum += a[i];
            pos.push_back(i);
        }
        if (!cando) {
            if (sum >= (w + 1) / 2) {
                print((int)pos.size(), '\n');
                for (auto i : pos) print(i, ' ');
                putchar('\n');
            } else {
                print(-1, '\n');
            }
        }
    }
    return 0;
}