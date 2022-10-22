#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int sum(int a, int b) {
    return (a + b) % mod;
}

inline int mul(int a, int b) {
    return (1ll * a * b) % mod;
}

int binpow(int x, int p) {
    if(!p) return 1;
    int q = binpow(x, p / 2);
    q = mul(q, q);
    if(p % 2) q = mul(q, x);
    return q;
}

int const N = 300005;

int fact[N];
int rfact[N];

void init() {
    fact[0] = 1;
    rfact[0] = 1;
    for(int i = 1;i < N;i++) {
        fact[i] = mul(fact[i - 1], i);
        rfact[i] = binpow(fact[i], mod - 2);
    }
}

int C(int n, int k) {
    if(n < k) return 0;
    else return mul( fact[n], mul(rfact[k], rfact[n - k]) );
}

int F(int n, int k) {
    return C(n + k - 1, k);
}

int main() {

    init();

    int f, w, h;

    scanf("%d %d %d", &f, &w, &h);

    if(f == 0) {
        if(w <= h) {
            puts("0");
        }else {
            puts("1");
        }
        return 0;
    }

    if(w == 0) {
        puts("1");
        return 0;
    }

    h++;

    int res = 0;

    int totU = 0;
    int totV = 0;

    for(int cnt = 1;cnt < N;cnt++) {
        if(w - 1ll * cnt * h >= 0 && f - cnt >= 0) {
            int U = mul( F(cnt, w - h * cnt), F(cnt, f - cnt) );
            U = mul(U, 2);
            totU = sum(totU, U);
//            cout << cnt << " a\n";
        }
        if(f >= cnt && w >= cnt) {
            int V = mul( F(cnt, f - cnt), F(cnt, w - cnt) );
            V = mul(V, 2);
            totV = sum(totV, V);
        }
    }

    for(int cnt = 1;cnt < N;cnt++) {
        if(w - 1ll * h * cnt >= 0 && f - cnt - 1 >= 0) {
//            cout << cnt << " b\n";
            int U = mul( F(cnt, w - h * cnt), F(cnt + 1, f - cnt - 1) );
            totU = sum(totU, U);
        }
        if(w - cnt >= 0 && f - cnt - 1 >= 0) {
            int V = mul( F(cnt, w - cnt), F(cnt + 1, f - cnt - 1) );
            totV = sum(totV, V);
        }
    }

    for(int cnt = 1;cnt < N;cnt++) {
        if(w - 1ll * h * (cnt + 1) >= 0 && f - cnt >= 0) {
            int U = mul( F(cnt + 1, w - h * (cnt + 1)), F(cnt, f - cnt) );
            totU = sum(totU, U);
//            cout << cnt << " c\n";
        }
        if(w - (cnt + 1) >= 0 && f - cnt >= 0) {
            int V = mul( F(cnt + 1, w - (cnt + 1)), F(cnt, f - cnt) );
            totV = sum(totV, V);
        }
    }

    printf("%d\n", mul(totU, binpow(totV, mod - 2)));

    return 0;
}