#include <cstdio>
#include <iostream>
#include <algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int, int> PII;
typedef long long LL;
const int N = 2005, S = 200005, P = 1e9 + 7;
int n, m, f[N], K, fact[S], infact[S];
PII e[N];
int power(int a, int b) {
    int res = 1;
    while(b) {
        if(b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}
int C(int n, int k) {
    return (LL)fact[n] * infact[k] % P * infact[n - k] % P;
}
int main() {
    scanf("%d%d%d", &n, &m, &K);
    int L = n + m;
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= L; i++)
        fact[i] = (LL) fact[i - 1] * i % P;
        
    infact[L] = power(fact[L], P - 2);
    for (int i = L - 1; i; i--)
        infact[i] = (LL) infact[i + 1] * (i + 1) % P;
    for (int i = 1; i <= K; i++) scanf("%d%d", &e[i].x, &e[i].y);
    sort(e + 1, e + 1 + K);
    e[++K] = make_pair(n, m);
    for (int i = 1; i <= K; i++) {
        f[i] = C(e[i].x + e[i].y - 2, e[i].x - 1);
        for (int j = 1; j < i; j++) {
            if(e[j].y > e[i].y) continue;
            f[i] = (((LL)f[i] - (LL)f[j] * C(e[i].x - e[j].x + e[i].y - e[j].y, e[i].x - e[j].x)) % P + P) % P;
        }
    }
    printf("%d\n", f[K]);
    return 0;
}