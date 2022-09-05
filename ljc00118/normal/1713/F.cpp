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

int n;

void fmt(vector <int> &a, int base) {
    for (int len = 1; len < (1 << base); len <<= 1) {
        for (int i = 0; i < (1 << base); i += (len << 1)) {
            for (int j = 0; j < len; j++) {
                a[i + j + len] ^= a[i + j];
            }
        }
    }
}

vector <int> solve(vector <int> a) {
    int n = (int)a.size(), base = 0;
    while ((1 << base) < n) ++base;
    vector <int> tmp;
    if ((1 << base) != n) {
        int len = n - (1 << (base - 1));
        vector <int> b(len);
        for (int i = 0; i < len; i++) b[i] = a[i] ^ a[i + (1 << (base - 1))];
        vector <int> lost = solve(b); tmp = lost;
        --base;
        lost.resize(1 << base); fmt(lost, base);
        vector <int> ans(1 << base);
        for (int i = 0; i < (1 << base); i++) ans[i] = (lost[i] ^ a[len + i]);
        a = ans;
    }
    // if (lost.size()) fprintf(stderr, "%d %d\n", (int)a.size(), lost[0]);
    fmt(a, base);
    for (auto i : tmp) a.push_back(i);
    return a;
}

int main() {
    read(n);
    vector <int> a(n);
    for (int i = 0; i < n; i++) read(a[i]);
    reverse(a.begin(), a.end());
    vector <int> ans = solve(a);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < n; i++) print(ans[i], i == n - 1 ? '\n' : ' ');
    return 0;
}


// 3 2 1 0
// 3 1 2 0