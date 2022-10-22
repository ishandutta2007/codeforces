#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;
const double pi = acos(-1.0);

const int N = 2e5 + 5;

void calc_sub(ll* a, ll* b, ll* c) {
    int f = 0;
    for(int i = 0;i < 2 * N;i++) {
        if(f) {
            if(!a[i]) {
                c[i] = !a[i] - b[i];
            }else {
                if(!a[i] >= b[i]) {
                    c[i] = !a[i] - b[i];
                    f = 0;
                }else {
                    c[i] = 2 + !a[i] - b[i];
                }
            }
        }else {
            if(a[i] >= b[i]) {
                c[i] = a[i] - b[i];
            }else {
                c[i] = 2 + a[i] - b[i];
                f = 1;
            }
        }
    }
}

void calc_sum(ll* a, ll* b, ll* c) {
    int md = 0;
    for(int i = 0;i < 2 * N;i++) {
        c[i] = (a[i] + b[i] + md) % 2;
        md = (a[i] + b[i] + md) / 2;
    }
}

int cmp(ll* p, ll *m) {
    for(int i = 2 * N - 1;i >= 0;i--) {
        if(p[i] < m[i]) {
            return -1;
        }
        if(p[i] > m[i]) {
            return +1;
        }
    }
    return 0;
}

bool check_less(int x, int i, ll* A, ll* PA) {
    if(!x) return true;
    int q = 40;
    while(!((1ll << q) & x)) q--;
    int j = i + q;
    if(PA[2 * N - 1] - PA[j] > 0) {
        return true;
    }
    for(;j >= i;j--) {
        int cur_x = (x >> (j - i)) & 1;
        int cur_A = A[j];
        if(cur_x > cur_A) {
            return false;
        }
        if(cur_x < cur_A) {
            return true;
        }
    }
    return true;
}

bool check_great(int x, int i, ll* A, ll* PA) {
    if(!x) {
        if(PA[2 * N - 1] == 0) {
            return true;
        }else {
            return false;
        }
    }
    int q = 40;
    while(!((1ll << q) & x)) q--;
    int j = i + q;
    if(PA[2 * N - 1] - PA[j] > 0) {
        return false;
    }
    for(;j >= i;j--) {
        int cur_x = (x >> (j - i)) & 1;
        int cur_A = A[j];
        if(cur_x > cur_A) {
            return true;
        }
        if(cur_x < cur_A) {
            return false;
        }
    }
    if(i > 0 && PA[i - 1] > 0) {
        return false;
    }else {
        return true;
    }
}

int n, k;
int a[N];
ll p[2 * N];
ll m[2 * N];
ll S[2 * N];
ll PS[2 * N];
ll K[2 * N];
int sgn;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 0;i <= 40;i++) {
        if((1ll << i) & ll(k)) {
            K[i] = 1;
        }
    }

    ll tmp = 0;
    for(int i = 0;i <= n;i++) {
        scanf("%d", &a[i]);
        tmp += a[i] * (1ll << i);
        if(a[i] >= 0) {
            p[i] = a[i];
        }else {
            m[i] = -a[i];
        }
    }

    for(int i = 0;i + 1 < 2 * N;i++) {
        p[i + 1] += p[i] / 2;
        p[i] %= 2;
        m[i + 1] += m[i] / 2;
        m[i] %= 2;
    }

    sgn = cmp(p, m);

    if(!sgn) {
        printf("%d\n", n);
        return 0;
    }

    if(sgn > 0) {
        calc_sub(p, m, S);
    }else {
        calc_sub(m, p, S);
    }

    PS[0] = S[0];
    for(int i = 1;i < 2 * N;i++) {
        PS[i] = PS[i - 1] + S[i];
    }

//    cout << tmp << " : ";

//    for(int i = 0;i < 10;i++) {
//        cout << S[i];
//    }

//    cout << "\n";

    int res = 0;

    for(int i = 0;i <= n;i++) {
        if(i > 0 && PS[i - 1] > 0) continue;
//        cout << i << " : " << a[i] - (tmp >> i) << " ?\n";
        int x1 = a[i] + k;
        int x2 = a[i] - k;
        if(sgn > 0) {
            if(x1 >= 0) {
                if(!check_great(x1, i, S, PS)) {
                    continue;
                }
            }else {
                continue;
            }
            if(x2 <= 0) { }
            else {
                if(!check_less(x2, i, S, PS)) {
                    continue;
                }
            }
        }else {
            if(x1 >= 0) { }
            else {
                if(!check_less(-x1, i, S, PS)) {
                    continue;
                }
            }
            if(x2 > 0) {
                continue;
            }else {
                if(!check_great(-x2, i, S, PS)) {
                    continue;
                }
            }
        }
        if(i == n && check_less(abs(a[i]), i, S, PS) && check_great(abs(a[i]), i, S, PS)) {}
        else {
            res++;
        }
    }

    printf("%d\n", res);

    return 0;
}