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

const int N = 50000 * 24 + 1;

bitset <N> f[51][26];
vector <int> ans1, ans2;
int a[55];
int n, sum, maxn;

int main() {
    read(n);
    for(register int i = 1; i <= n * 2; i++) read(a[i]);
    sort(a + 1, a + n * 2 + 1); reverse(a + 1, a + n * 2 + 1);
    ans1.push_back(a[n * 2 - 1]); ans2.push_back(a[n * 2]);
    f[0][0][0] = 1;
    for(register int i = 1; i <= n * 2 - 2; i++) {
        f[i][0][0] = 1; sum += a[i];
        for(register int j = 1; j <= i && j <= n - 1; j++) {
            f[i][j] = f[i - 1][j] | (f[i - 1][j - 1] << a[i]);
        }
    }
    maxn = sum >> 1;
    while(!f[n * 2 - 2][n - 1][maxn]) --maxn;
    int now = n - 1;
    for(register int i = n * 2 - 2; i >= 1; i--) {
        if(maxn >= a[i] && now && f[i - 1][now - 1][maxn - a[i]]) {
            maxn -= a[i]; --now;
            ans1.push_back(a[i]);
        } else ans2.push_back(a[i]);
    }
    sort(ans1.begin(), ans1.end());
    sort(ans2.begin(), ans2.end());
    reverse(ans2.begin(), ans2.end());
    for(register int i = 0; i < n; i++) print(ans1[i], ' ');
    putchar('\n');
    for(register int i = 0; i < n; i++) print(ans2[i], ' ');
    putchar('\n');
    return 0;
}