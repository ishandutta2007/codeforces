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

const int N = 505;

int f[N][N];
char c[N];
int n;

int dfs1(int l, int r) {
    if(l >= r) return 0;
    if(f[l][r] != -1) return f[l][r];
    int &ans = f[l][r]; ans = 2333;
    for(register int i = l; i < r; i++) ans = min(ans, dfs1(l, i) + dfs1(i + 1, r) + (c[l] != c[i + 1]));
    return ans;
}

int main() {
    memset(f, -1, sizeof(f));
    read(n); scanf("%s", c + 1);
    print(dfs1(1, n) + 1, '\n');
    return 0;
} //