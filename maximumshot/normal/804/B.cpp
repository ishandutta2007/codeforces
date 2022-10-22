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

inline int Mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int const N = 1e6 + 5;

char s[N];
int pw[N];

int main() {

    pw[0] = 1;
    for(int i = 1;i < N;i++) {
        pw[i] = Mul(pw[i - 1], 2);
    }

    scanf("%s", s);

    int n = strlen(s);

    int cur = 0;
    int tot = 0;

    for(int i = 0;i < n;i++) {
        if(s[i] != 'a' && s[i] != 'b') {
            cur = 0;
            tot = Sum(tot, 1);
            continue;
        }
        if(s[i] == 'a') {
            tot = Sum(tot, 1);
            cur = Sum(cur, 1);
            continue;
        }
        tot = Sum(tot, pw[cur]);
    }

    printf("%d\n", ((tot - n) % mod + mod) % mod);

    return 0;
}