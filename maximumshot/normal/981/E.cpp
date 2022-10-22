#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e4 + 5;

int n, q;
bitset< N > tot;

void rec(int l, int r, bitset< N > dp, vec< pair< pii, int > > seq) {
    int m = (l + r) >> 1;
    vec< pair< pii, int > > L, R;
    for(pair< pii, int > pr : seq) {
        int lx, rx, vx;
        tie(lx, rx) = pr.first;
        vx = pr.second;
        if(lx <= l && r <= rx) {
            dp |= dp << vx;
            continue;
        }
        if(lx <= m && rx >= l) L.push_back(pr);
        if(lx <= r && rx > m) R.push_back(pr);
    }
    if(l == r) {
        tot |= dp;
    }else {
        rec(l, m, dp, L);
        rec(m + 1, r, dp, R);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &q);

    vec< pair< pii, int > > seq;

    for(int i = 0;i < q;i++) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        seq.push_back({{l, r}, x});
    }

    bitset< N > cur;
    cur[0] = 1;

    rec(1, n, cur, seq);

    int cnt = 0;

    for(int i = 1;i <= n;i++) {
        cnt += tot[i];
    }

    printf("%d\n", cnt);

    for(int i = 1;i <= n;i++) {
        if(tot[i]) {
            printf("%d ", i);
        }
    }

    printf("\n");

    return 0;
}