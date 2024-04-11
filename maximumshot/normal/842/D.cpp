#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 3e5 + 5;
int const LOG = 19;

int a[N];
int n, m;
int S;
int sz = 1;
int cnt[N * LOG];
int nxt[N * LOG][2];

void add(int x) {
    int v = 0;
    for(int cur, i = LOG - 1;i >= 0;i--) {
        cur = (x >> i) & 1;
        if(nxt[v][cur] == -1) {
            nxt[v][cur] = sz++;
        }
        v = nxt[v][cur];
        cnt[v]++;
    }
}

int kth(int k) {
    if(k < 1 || k > n) return -1;
    int v = 0;
    int res = 0;
    for(int cur, i = LOG - 1;i >= 0;i--) {
        cur = (S >> i) & 1;
        int vl = nxt[v][cur];
        int vr = nxt[v][cur ^ 1];
        int cl = vl == -1 ? 0 : cnt[vl];
        int cr = vr == -1 ? 0 : cnt[vr];
        if(cl >= k) {
            v = vl;
        }else {
            k -= cl;
            v = vr;
            res |= (1 << i);
        }
    }
    return res;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 0;i < N * LOG;i++) {
        nxt[i][0] = nxt[i][1] = -1;
    }

    {
        set< int > setik;
        for(int i = 1;i <= n;i++) {
            scanf("%d", &a[i]);
            if(!setik.count(a[i])) {
                add(a[i]);
                setik.insert(a[i]);
            }
        }

    }

    for(int x, iter = 0;iter < m;iter++) {
        scanf("%d", &x);
        S ^= x;
        int bl = -1;
        int br = n;
        int bm;
        while(br - bl > 1) {
            bm = (bl + br) / 2;
            if(kth(bm + 1) == bm) {
                bl = bm;
            }else {
                br = bm;
            }
        }
#ifdef debug
        for(int i = 1;i <= n;i++) {
            cout << (a[i] ^ S) << " ";
        }
        cout << " = ";
#endif
        printf("%d\n", br);
    }

    return 0;
}