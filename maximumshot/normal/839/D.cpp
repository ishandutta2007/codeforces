#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

inline void Add(int & x, int y) {
    x = Sum(x, y);
}

int const X = 1e6 + 5;
int const N = 2e5 + 5;

int n;
int f[X];
int cnt[X];
int pw[N];
int ans[X];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    pw[0] = 1;
    for(int i = 1;i < N;i++) {
        pw[i] = Mul(pw[i - 1], 2);
    }

    scanf("%d", &n);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        f[x]++;
    }

    for(int i = 1;i < X;i++) {
        for(int j = i;j < X;j += i) {
            cnt[i] += f[j];
        }
    }

    int r = 0;

    for(int x = X - 1;x > 1;x--) {
        if(!cnt[x]) continue;
        ans[x] = Mul(cnt[x], pw[cnt[x] - 1]);
        for(int y = x+x;y < X;y += x) {
            Add(ans[x], (mod - ans[y]) % mod);
        }
        Add(r, Mul(ans[x], x));
    }

    printf("%d\n", r);

    return 0;
}