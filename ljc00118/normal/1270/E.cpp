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

const int N = 2e3 + 5;

int x[N], y[N];
int n;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(x[i]), read(y[i]);
    for (int pw = 2, opt = 0; ; pw *= (1 << opt), opt ^= 1) {
        if (opt == 0) {
            int now = ((x[1] + y[1]) % pw + pw) % pw;
            vector <int> ans;
            for (int i = 2; i <= n; i++) {
                if (((x[i] + y[i]) % pw + pw) % pw != now) {
                    ans.push_back(i);
                }
            }
            if (ans.size()) {
                print((int)ans.size(), '\n');
                for (int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
                putchar('\n'); return 0;
            }
        }
        if (opt == 1) {
            int now = (x[1] % pw + pw) % pw;
            vector <int> ans;
            for (int i = 2; i <= n; i++) {
                if ((x[i] % pw + pw) % pw != now) {
                    ans.push_back(i);
                }
            }
            if (ans.size()) {
                print((int)ans.size(), '\n');
                for (int i = 0; i < (int)ans.size(); i++) print(ans[i], ' ');
                putchar('\n'); return 0;
            }
        }
    }
    return 0;
}