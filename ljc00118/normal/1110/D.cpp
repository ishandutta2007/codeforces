#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 1e6 + 5;

int f[N][3][3];
int cnt[N];
int n, m;

int main() {
    read(n); read(m); m += 2;
    for(register int i = 1; i <= n; i++) {
        int t; read(t);
        cnt[t + 2]++;
    }
    memset(f, -0x3f, sizeof(f));
    f[2][0][0] = 0;
    for(register int i = 3; i <= m + 5; i++) {
        for(register int j = 0; j <= 2; j++) {
            for(register int k = 0; k <= 2; k++) {
                if(cnt[i - 1] < k || cnt[i - 2] < j + k || f[i - 1][j][k] < 0) continue;
                for(register int t = 0; t <= min(2, min(cnt[i], min(cnt[i - 1] - k, cnt[i - 2] - k - j))); t++) {
                    f[i][k][t] = max(f[i][k][t], f[i - 1][j][k] + t + (cnt[i - 2] - j - k - t) / 3);
                }
            }
        }
    }
    cout << f[m + 5][0][0] << endl;
    return 0;
}