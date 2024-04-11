#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int X = 1e6 + 5;

int prime[X];
vec< int > pr[X];
int cnt_bit[1 << 10];

void precalc() {
    fill(prime, prime + X, 1);
    prime[0] = prime[1] = 0;
    for(int p = 2;p * p < X;p++) {
        if(!prime[p]) continue;
        for(int x = p * p;x < X;x += p) {
            prime[x] = 0;
        }
    }
    for(int p = 2;p < X;p++) {
        if(!prime[p]) continue;
        for(int x = p;x < X;x += p) {
            pr[x].push_back(p);
        }
    }
    for(int i = 1;i < (1 << 10);i++) {
        cnt_bit[i] = cnt_bit[i >> 1] + (i & 1);
    }
    for(int i = 0;i < (1 << 10);i++) {
        cnt_bit[i] &= 1;
    }
}

int calc(int R, int p) {
    int res = R;
    int sz = (int)pr[p].size();
    for(int mask = 1;mask < (1 << sz);mask++) {
        int vl = 1;
        for(int i = 0;i < sz;i++) {
            if((1 << i) & mask) {
                vl *= pr[p][i];
            }
        }
        if(cnt_bit[mask]) {
            res -= R / vl;
        }else {
            res += R / vl;
        }
    }
    return res;
}

void solve() {
    int x, p, k;
    scanf("%d %d %d", &x, &p, &k);
    int bl = x;
    int br = inf;
    int bm;
    int tmp = calc(x, p);
    while(br - bl > 1) {
        bm = (bl + br) >> 1;
        if(calc(bm, p) - tmp >= k) {
            br = bm;
        }else {
            bl = bm;
        }
    }
    printf("%d\n", br);
}

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int t;

    scanf("%d", &t);

    while(t--) {
        solve();
    }

    return 0;
}