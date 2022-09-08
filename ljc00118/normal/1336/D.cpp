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

const int N = 105;

int a[N], ans[N][2];
int n;

inline int C3(int n) { return n * (n - 1) * (n - 2) / 6; }

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> ans[0][0] >> ans[0][1];
    for (int i = 1; i < n; i++) {
        cout << "+ " << i << endl;
        cin >> ans[i][0] >> ans[i][1];
        if (ans[i][0] - ans[i - 1][0]) {
            for (int j = 2; j <= n; j++) {
                if (C3(j + 1) - C3(j) == ans[i][0] - ans[i - 1][0]) {
                    a[i] = j;
                    break;
                }
            }
        }
    }
    cout << "+ " << 1 << endl;
    cin >> ans[n][0] >> ans[n][1];
    if (a[1] == 0) {
        if (ans[n][0] - ans[n - 1][0]) a[1] = 1;
        else a[1] = 0;
    }
    if (a[3] == 0) {
        if (ans[2][1] - ans[1][1] == 0) a[3] = 0;
        else a[3] = 1;
    }
    a[2] = (ans[n][1] - ans[n - 1][1]) / (a[3] + 1) - 1;
    for (int i = 4; i <= n - 1; i++) {
        if (a[i] == 0) {
            if (ans[i - 1][1] - ans[i - 2][1] == (a[i - 2] + 1) * (a[i - 3] + 1)) a[i] = 0;
            else a[i] = 1;
        }
    }
    a[n] = ans[n - 1][1];
    for (int i = 2; i < n - 1; i++) a[n] -= (a[i - 1] + 1) * (a[i] + 1) * (a[i + 1] + 1);
    a[n] = a[n] / (a[n - 1] + 1) / (a[n - 2] + 1);
    cout << "!";
    for (int i = 1; i <= n; i++) cout << " " << a[i];
    cout << endl;
    return 0;
}