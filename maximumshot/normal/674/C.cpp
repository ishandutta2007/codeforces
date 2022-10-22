#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;
int const K = 55;

struct Line {
    double k, b; // y = k * x + b
    Line() : k(0), b(0) { }
    Line(double k, double b) : k(k), b(b) { }
    Line(Line const & other) : k(other.k), b(other.b) { }

    inline double intersect(Line const & other) const {
        return (other.b - b) / (k - other.k);
    }

    inline double get(double x0) const {
        return k * x0 + b;
    }
};

int n, k;
int t[N];

ll pref_t[N];
double pref_rt[N];
double pref_p[N];

void read() {
    scanf("%d %d", &n, &k);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &t[i]);
    }
}

void precalc() {
    for(int i = 1;i <= n;i++) {
        pref_t[i] = pref_t[i - 1] + t[i];
        pref_rt[i] = pref_rt[i - 1] + 1.0 / t[i];
        pref_p[i] = pref_p[i - 1] + 1.0 * pref_t[i] / t[i];
    }
}

Line st[N];
int sz;
int ptr;
double dp[K][N];

void clearStack() {
    sz = 0;
    ptr = 0;
}

void addLine(int l, int kk) {
    Line cur = Line(
        -pref_t[l],
        dp[kk - 1][l] - pref_p[l] + pref_t[l] * pref_rt[l]
    );
    while(sz > 1 && st[sz - 2].intersect(st[sz - 1]) > st[sz - 2].intersect(cur)) {
        sz--;
    }
    ptr = max(0, min(ptr, sz - 1));
    st[sz++] = cur;
}

void init() {
    for(int i = 0;i < K;i++) {
        for(int j = 0;j < N;j++) {
            dp[i][j] = 1e18;
        }
    }
}

int main() {

    init();
    read();
    precalc();

    for(int i = 1;i <= n;i++) {
        dp[1][i] = pref_p[i];
    }

    for(int kk = 2;kk <= k;kk++) {
        clearStack();
        for(int r = 1;r <= n;r++) {
            if(r >= kk) {
                double x0 = pref_rt[r];
                while(ptr + 1 < sz && st[ptr].intersect(st[ptr + 1]) < x0) {
                    ptr++;
                }
                dp[kk][r] = st[ptr].get(x0) + pref_p[r];
            }
            addLine(r, kk);
        }
    }

    printf("%.10lf\n", dp[k][n]);

    return 0;
}