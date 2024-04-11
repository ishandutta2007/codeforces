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

const int N = 3e5 + 5;

map <int, int> las[N];
int a[N], dp[N], id[N];
int T, n; ll ans;

int main() {
    read(T);
    while(T--) {
        read(n); ans = 0;
        for(register int i = 1; i <= n; i++) {
            read(a[i]); dp[i] = id[i] = 0;
            las[i].clear();
        }
        for(register int i = 1; i <= n; i++) {
            if(!las[id[i - 1]].count(a[i])) { id[i] = i; las[id[i]][a[i]] = i; continue; }
            int pos = las[id[i - 1]][a[i]];
            dp[i] = dp[pos - 1] + 1;
            if(id[pos - 1]) id[i] = id[pos - 1];
            else id[i] = i;
            las[id[i]][a[i]] = i;
            ans += dp[i];
        }
        print(ans, '\n');
    }
    return 0;
}