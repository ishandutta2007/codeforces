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

const int N = 1e5 + 5;

int n, m;
int f[N];
int pr[N];
int sf[N];
int fen[N];

int get_max(int p) {
    int res = 0;
    for(int cur = p;cur >= 0;cur = (cur & (cur + 1)) - 1) {
        res = max(res, fen[cur]);
    }
    return res;
}

void upd(int p, int v) {
    for(int cur = p;cur < N;cur |= (cur + 1)) {
        fen[cur] = max(fen[cur], v);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int l, r, i = 1;i <= n;i++) {
        scanf("%d %d", &l, &r);
        f[l]++;
        f[r + 1]--;
    }

    for(int i = 1;i <= m;i++) {
        f[i] += f[i - 1];
    }

    for(int i = 1;i <= m;i++) {
        pr[i] = 1 + get_max(f[i]);
        upd(f[i], pr[i]);
    }

    fill(fen, fen + N, 0);

    for(int i = m;i >= 1;i--) {
        sf[i] = 1 + get_max(f[i]);
        upd(f[i], sf[i]);
    }

    int res = 0;

    for(int i = 1;i <= m;i++) {
        res = max(res, pr[i] + sf[i] - 1);
    }

    printf("%d\n", res);

    return 0;
}