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

ull seed = 114514;
inline ull R() {
    seed ^= seed << 17;
    seed ^= seed >> 13;
    seed ^= seed << 5;
    return seed;
}

int cnt[1 << 18];
int h;

int query(int x, int y, int z) {
    cout << "? " << x << " " << y << " " << z << endl;
    int ans; cin >> ans; return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> h;
    for (int i = 1; i <= 422; i++) {
        int x = R() % ((1 << h) - 1) + 1;
        int y = R() % ((1 << h) - 1) + 1;
        while (y == x) y = R() % ((1 << h) - 1) + 1;
        int z = R() % ((1 << h) - 1) + 1;
        while (z == x || z == y) z = R() % ((1 << h) - 1) + 1;
        ++cnt[query(x, y, z)];
    }
    int mx1 = 0, mx2 = 0;
    for (int i = 1; i < (1 << h); i++) {
        if (cnt[i] > cnt[mx1]) mx2 = mx1, mx1 = i;
        else if (cnt[i] > cnt[mx2]) mx2 = i;
    }
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i < (1 << h); i++) {
        if (i == mx1 || i == mx2) continue;
        ++cnt[query(mx1, mx2, i)];
    }
    for (int i = 1; i < (1 << h); i++) {
        if (cnt[i] == 1) {
            cout << "! " << i << endl;
            break;
        }
    }
    return 0;
}