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

ll s[N];
int a[N];
int n, ans;

void solve(int opt) {
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    vector <int> pos;
    for (int i = 1; i < n; i++) {
        vector <int> new_pos;
        for (int j = 0; j < (int)pos.size(); j++) {
            int p = pos[j];
            if (s[i] - s[p] <= a[p] * 2) {
                new_pos.push_back(p);
            }
        }
        pos = new_pos;
        for (int j = 0; j < (int)pos.size(); j++) {
            int p = pos[j];
            if (a[p] > a[i + 1] || (opt && a[p] == a[i + 1])) {
                if ((a[p] ^ a[i + 1]) == s[i] - s[p]) {
                    ++ans;
                }
            }
        }
        pos.push_back(i);
    }
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    solve(0); reverse(a + 1, a + n + 1); solve(1);
    print(ans, '\n');
    return 0;
}