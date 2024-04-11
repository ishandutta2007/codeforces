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

const int N = 5205;

bool a[N][N];
int vis[N];
int n;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j += 4) {
            char c; cin >> c; int x = c - '0';
            if(c >= 'A' && c <= 'F') x = c - 'A' + 10;
            a[i][j] = (x >> 3) & 1;
            a[i][j + 1] = (x >> 2) & 1;
            a[i][j + 2] = (x >> 1) & 1;
            a[i][j + 3] = x & 1;
        }
    }
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= n; j++) {
            if(a[i][j] != a[i][j + 1]) vis[j] = 1;
            if(a[i][j] != a[i + 1][j]) vis[i] = 1;
        }
    }
    int sum = 0; vis[n] = 1;
    for(register int i = 1; i <= n; i++) sum += vis[i];
    for(register int i = n; i >= 1; i--) {
        int res = 0;
        for(register int j = i; j <= n; j += i) res += vis[j];
        if(res == sum) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
} // I am faker