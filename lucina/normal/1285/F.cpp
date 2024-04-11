#include<bits/stdc++.h>
using namespace std;
int const nax = 1e5;
int n, a[nax + 5];
int mu[nax + 5];
int cnt[nax + 5];
int st[nax + 5];
int top;
bool has[nax + 5];
vector<int> factor[nax + 5];


inline void add (int x) {
    for (int j : factor[x])
        ++ cnt[j];
}
inline void pop (int x) {
    for (int j : factor[x])
        -- cnt[j];
}

inline int coprime (int x) {
    int res = 0;
    for (int j : factor[x])
        res += cnt[j] * mu[j];
    return res;
}
long long ans ;

int main () {
    scanf("%d", &n);
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        scanf("%d", &x);
        has[x] = true;
        ans = max(ans, (long long)x);
    }
    mu[1] = 1;
    for (int c = 1 ; c <= nax ; ++ c) {
        factor[c].emplace_back(c);
        for (int j = c + c ; j <= nax ; j += c) {
            mu[j] -= mu[c];
            factor[j].emplace_back(c);
        }
    }

    for (int g = 1 ; g <= nax ; ++ g) {
        top = 0;
        for (int v = nax / g ; v >= 1 ; -- v) {
            if (!has[v * g]) continue;
            int C = coprime(v);
            while (C > 0) {
                if (__gcd(st[top], v) == 1)
                    ans = max(ans, 1LL * v * st[top] * g), -- C;
                pop(st[top -- ]);
            }
            add(st[++ top] = v);
        }
        while (top > 0) {
            pop(st[top --]);
        }
    }
    printf("%lld\n", ans);
}