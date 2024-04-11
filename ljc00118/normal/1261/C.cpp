#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
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

vector < vector <int> > a, s, s2, ans;
vector <int> tmp;
char c[N];
int n, m;

void add1(int x, int y, int val) {
    if(x > n + 1 || y > m + 1) return;
    s[max(x, 0)][max(y, 0)] += val;
}

void add2(int x, int y, int val) {
    if(x > n + 1 || y > m + 1) return;
    // cout << x << " " << y << " " << val << endl;
    s2[max(x, 0)][max(y, 0)] += val;
}

bool check(int mid) {
    // cout << "mid = " << mid << endl;
    for(register int i = 0; i <= n + 1; i++) {
        for(register int j = 0; j <= m + 1; j++) {
            s[i][j] = s2[i][j] = 0;
        }
    }
    for(register int i = 0; i <= n + 1; i++) {
        for(register int j = 0; j <= m + 1; j++) {
            if(a[i][j] == 0) {
                add1(i - mid, j - mid, 1);
                add1(i - mid, j + mid + 1, -1);
                add1(i + mid + 1, j - mid, -1);
                add1(i + mid + 1, j + mid + 1, 1);
            }
        }
    }
    for(register int i = 0; i <= n + 1; i++) {
        for(register int j = 0; j <= m + 1; j++) {
            if(i) s[i][j] += s[i - 1][j];
            if(j) s[i][j] += s[i][j - 1];
            if(i && j) s[i][j] -= s[i - 1][j - 1];
            if(!s[i][j] && i && j && i != n + 1 && j != m + 1) {
                add2(i - mid, j - mid, 1);
                add2(i - mid, j + mid + 1, -1);
                add2(i + mid + 1, j - mid, -1);
                add2(i + mid + 1, j + mid + 1, 1);
            }
        }
    }
    for(register int i = 0; i <= n + 1; i++) {
        for(register int j = 0; j <= m + 1; j++) {
            if(i) s2[i][j] += s2[i - 1][j];
            if(j) s2[i][j] += s2[i][j - 1];
            if(i && j) s2[i][j] -= s2[i - 1][j - 1];
            if(a[i][j] != (s2[i][j] != 0)) return 0;
        }
    }
    return 1;
}

int main() {
    read(n); read(m); tmp.resize(m + 2);
    for(register int i = 0; i <= n + 1; i++) a.push_back(tmp);
    s = s2 = a;
    for(register int i = 1; i <= n; i++) {
        scanf("%s", c + 1);
        for(register int j = 1; j <= m; j++) {
            a[i][j] = (c[j] == 'X');
        }
    }
    int l = 0, r = n + m - 2, res = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(check(mid)) ans = s, res = mid, l = mid + 1;
        else r = mid - 1;
    }
    print(res, '\n');
    for(register int i = 1; i <= n; i++) {
        for(register int j = 1; j <= m; j++) {
            if(!ans[i][j]) {
                putchar('X');
            } else {
                putchar('.');
            }
        }
        putchar('\n');
    }
    return 0;
}