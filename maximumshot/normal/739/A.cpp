#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 100005;

int n, m;
int a[N];

int fen[N];

void add_val(int pos, int val) {
    for(int cur = pos;cur < N;cur |= (cur + 1)) fen[cur] += val;
}

int get(int pos) {
    int res = 0;
    for(int cur = pos;cur >= 0;cur = (cur & (cur + 1)) - 1) res += fen[cur];
    return res;
}

int mex() {
    int bl, br, bm;
    bl = 0;
    br = N - 1;
    while(br - bl > 1) {
        bm = (bl + br) / 2;
        if(get(bm) == bm + 1) bl = bm + 1;
        else br = bm;
    }
    if(get(bl) < bl + 1) return bl;
    else return br;
}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) a[i] = 0;

    int mn = inf;

    vec< pii > seg;

    for(int l, r, i = 0;i < m;i++) {
        scanf("%d %d", &l, &r);
        seg.push_back({r, -l});
        mn = min(mn, r - l + 1);
    }

    printf("%d\n", mn);

    for(int i = 1;i <= n;i++) {
        printf("%d ", (i - 1) % mn);
    }

    return 0;
}