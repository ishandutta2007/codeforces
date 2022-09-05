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

const int N = 1205;

vector <int> a, id;
int n;

int main() {
    read(n); a.resize(n * 6, 1);
    for (int i = 1; i <= n * 3; i++) {
        int x; read(x);
        a[x - 1] = 0;
    }
    id.resize(n * 6);
    for (int i = 1; i <= n * 6; i++) id[i - 1] = i;
    for (int now = 0; a.size(); now ^= 1) {
        int len = (int)a.size(), L = 0, R = len - 1;
        for (int l = 0, r; l < len; l = r + 1) {
            r = l;
            while (r + 1 < len && a[r + 1] == a[l]) ++r;
            if ((r - l + 1) % 3 != 0) break;
            L = r + 1;
        }
        for (int r = len - 1, l; r >= 0; r = l - 1) {
            l = r;
            while (l - 1 >= 0 && a[l - 1] == a[r]) --l;
            if ((r - l + 1) % 3 != 0) break;
            R = l - 1;
        }
        int pos = -1;
        for (int i = L; i <= R - 2; i++) {
            if (a[i] == now && a[i + 1] == now && a[i + 2] == now) {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            for (int i = 0; i < len - 2; i++) {
                if (a[i] == now && a[i + 1] == now && a[i + 2] == now) {
                    pos = i;
                    break;
                }
            }
        }
        assert(pos != -1);
        print(id[pos], ' '); print(id[pos + 1], ' '); print(id[pos + 2], '\n');
        for (int i = pos + 3; i < len; i++) {
            a[i - 3] = a[i];
            id[i - 3] = id[i];
        }
        a.resize(len - 3); id.resize(len - 3);
    }
    return 0;
}