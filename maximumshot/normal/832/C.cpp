#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const ITER = 100;
int const N = 1e5 + 5;
int const M = 1e6 + 5;

int n, ss;
int x[N];
int v[N];
int type[N];
ld s;
int c1[M];
int c2[M];

inline ld Sqr(ld x) {
    return x * x;
}

bool check(ld T, bool pr = 0) {
    for(int i = 0;i < M;i++) {
        c1[i] = 0;
        c2[i] = 0;
    }
    ld xi, vi, ql, qr;
    for(int tl, tr, i = 1;i <= n;i++) {
        if(type[i] == 1) {
            xi = x[i];
            vi = v[i];

            {
                ql = 0;
                qr = 1e6;
                qr = min(qr, (xi * (s - vi) / vi) + xi);
                qr = min(qr, (T * (Sqr(s) - Sqr(vi)) + xi * vi) / s);
                ql = max(ql, xi);
                tl = ceil(ql);
                tr = floor(qr);
                if(tl <= tr) {
                    c1[tl]++;
                    c1[tr + 1]--;
                }
            }

            if(xi / vi <= T) {
                tl = 0;
                tr = 1000 * 1000;
                if(tl <= tr) {
                    c1[tl]++;
                    c1[tr + 1]--;
                }
            }
        }else {
            xi = 1e6 - x[i];
            vi = v[i];

            {
                ql = 0;
                qr = 1e6;
                qr = min(qr, (xi * (s - vi) / vi) + xi);
                qr = min(qr, (T * (Sqr(s) - Sqr(vi)) + xi * vi) / s);
                ql = max(ql, xi);
                tl = ceil(ql);
                tr = floor(qr);
                tl = 1e6 - tl;
                tr = 1e6 - tr;
                swap(tl, tr);
                if(tl <= tr) {
                    c2[tl]++;
                    c2[tr + 1]--;
                }
            }

            if(xi / vi <= T) {
                tl = 0;
                tr = 1000 * 1000;
                if(tl <= tr) {
                    c2[tl]++;
                    c2[tr + 1]--;
                }
            }
        }
    }

    for(int i = 1;i < M;i++) {
        c1[i] += c1[i - 1];
        c2[i] += c2[i - 1];
        if(c1[i] > 0 && c2[i] > 0) {
            return 1;
        }
    }
    return 0;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &ss);

    s = ss;

    for(int i = 1;i <= n;i++) {
        scanf("%d %d %d", &x[i], &v[i], &type[i]);
    }

    ld bl = 0;
    ld br = 1e7;
    ld bm;

    for(int iter = 0;iter < ITER;iter++) {
        bm = (bl + br) * (ld)0.5;
        if(check(bm)) {
            br = bm;
        }else {
            bl = bm;
        }
    }

    printf("%.10lf\n", (double)bl);

    return 0;
}