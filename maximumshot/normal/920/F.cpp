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
const int N = 3e5 + 5;

int n, m;
int a[N];
ll fen[N];
int D[X];
int nx[N];

void precalc() {
    for(int i = 1;i < X;i++) {
        for(int j = i;j < X;j += i) {
            D[j]++;
        }
    }
}

void update(int pos, int val) {
    int delt = val - a[pos];
    a[pos] = val;
    for(int cur = pos;cur <= n;cur |= (cur + 1)) {
        fen[cur] += delt;
    }
}

ll get(int l, int r) {
    ll res = 0;
    for(int cur = r;cur > 0;cur = (cur & (cur + 1)) - 1) {
        res += fen[cur];
    }
    for(int cur = l - 1;cur > 0;cur = (cur & (cur + 1)) - 1) {
        res -= fen[cur];
    }
    return res;
}

int next(int pos) {
    if(nx[pos] > n) return n + 1;
    if(a[nx[pos]] == D[a[nx[pos]]]) {
        nx[pos] = next(nx[pos]);
    }
    return nx[pos];
}

int main() {

    precalc();

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        nx[i] = i + 1;
        for(int cur = i;cur <= n;cur |= (cur + 1)) {
            fen[cur] += a[i];
        }
    }

    for(int t, l, r, iter = 0;iter < m;iter++) {
        scanf("%d %d %d", &t, &l, &r);
        if(t == 1) {
            if(a[l] == D[a[l]]) {
                l = next(l);
            }
            while(l <= r) {
                update(l, D[a[l]]);
                l = next(l);
            }
        }else {
#ifdef debug
            printf("%lld\n", get(l, r));
#else
            printf("%I64d\n", get(l, r));
#endif
        }
    }

    return 0;
}