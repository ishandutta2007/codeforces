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

const int N = 1005;

int ans[N];
int n, block = 1, now;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (i + n / i - (n % i == 0) < block + n / block - (n % block == 0)) block = i;
    }
    while (now < n - block - n / block + (n % block == 0)) {
        cout << block << endl;
        int cnt = block;
        for (int i = 1; cnt; i++) {
            if (!ans[i] && i % block != 0) {
                cout << i << " ";
                ans[i] = 1; --cnt; ++now;
            }
        }
        cout << endl;
        int fir; cin >> fir;
        for (int i = 0; i < block; i++) {
            if (ans[(fir + i - 1) % n + 1]) {
                ans[(fir + i - 1) % n + 1] = 0;
                --now;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}