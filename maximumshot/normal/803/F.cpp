#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int Sum(int a, int b) {
    return (a + b) % mod;
}

inline int Raz(int a, int b) {
    return ((a - b) % mod + mod) % mod;
}

inline void Add(int & x, int y) {
    x = Sum(x, y);
}

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int const N = 1e5 + 5;

int n;
int a[N];
int cn[N];
int dp[N];
int pw[N];
bool prime[N];
vec< int > d[N];
int ml[N];

int main() {

    for(int i = 0;i < N;i++) {
        prime[i] = 1;
        ml[i] = 1;
    }

    prime[0] = prime[1] = 0;

    for(int i = 2;i * i < N;i++) {
        if(!prime[i]) continue;
        for(int j = i * i;j < N;j += i) {
            prime[j] = 0;
        }
    }

    for(int i = 2;i < N;i++) {
        if(!prime[i]) continue;
        for(int j = i;j < N;j += i) {
            d[j].push_back(i);
            ml[j] *= i;
        }
    }

    pw[0] = 1;

    for(int i = 1;i < N;i++) {
        pw[i] = Mul(pw[i - 1], 2);
    }

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        cn[a[i]]++;
    }

    int res = Raz(pw[n], 1);

    for(int g = 2;g < N;g++) {
        if(ml[g] != g) continue;
        int tmp = 0;
        for(int x = g;x < N;x += g) {
            tmp += cn[x];
        }
        tmp = Raz(pw[tmp], 1);
        if((int)d[g].size() % 2) {
            res = Raz(res, tmp);
        }else {
            res = Sum(res, tmp);
        }
    }

    printf("%d\n", res);

    return 0;
}