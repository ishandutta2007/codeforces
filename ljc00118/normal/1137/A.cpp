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

const int N = 1005;

int a[N][N], ans[N][N], ans2[N][N], b[N];
int n, m;

int main() {
    read(n); read(m);
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            read(a[i][j]);
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) b[j] = a[i][j];
        sort(b + 1, b + m + 1);
        int big = unique(b + 1, b + m + 1) - b - 1;
        for(register int j = 1; j <= m; j++) {
            int tmp = lower_bound(b + 1, b + big + 1, a[i][j]) - b;
            ans[i][j] = max(ans[i][j], tmp);
            ans2[i][j] = max(ans2[i][j], big - tmp);
        }
    }
    for(register int j = 1; j <= m; j++) {
        for(register int i = 1; i <= n; i++) b[i] = a[i][j];
        sort(b + 1, b + n + 1);
        int big = unique(b + 1, b + n + 1) - b - 1;
        for(register int i = 1; i <= n; i++) {
            int tmp = lower_bound(b + 1, b + big + 1, a[i][j]) - b;
            ans[i][j] = max(ans[i][j], tmp);
            ans2[i][j] = max(ans2[i][j], big - tmp);
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            print(ans[i][j] + ans2[i][j], j == m ? '\n' : ' ');
        }
    }
    return 0;
} //