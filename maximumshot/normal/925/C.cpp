#include <bits/stdc++.h>

using namespace std;

#define ALL(x) begin(x), end(x)
#define vec vector

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = ll(1e18);

const int N = 2e5 + 5;
const int LOG = 61;
const int K = N * LOG + 5;

int n;
ll b[N];
int nxt[K][2];
int cnt[K];
int sz = 1;

void add(ll x) {
    int v = 0;
    for(int i = LOG - 1;i >= 0;i--) {
        int xi = (1ll << i) & x ? 1 : 0;
        if(nxt[v][xi] == -1) {
            nxt[v][xi] = sz++;
        }
        v = nxt[v][xi];
        cnt[v]++;
    }
}

void del(ll x) {
    int v = 0;
    for(int i = LOG - 1;i >= 0;i--) {
        int xi = (1ll << i) & x ? 1 : 0;
        v = nxt[v][xi];
        cnt[v]--;
    }
}

ll get_min(ll xr, ll vl) {
    for(int i = 0;i < LOG;i++) {
        if((1ll << i) & vl) continue;
        int v = 0;
        int ok = 1;
        ll res = 0;
        for(int j = LOG - 1;j > i;j--) {
            int xj = (1ll << j) & xr ? 1 : 0;
            int yj = (1ll << j) & vl ? 1 : 0;
            yj ^= xj;
            if(yj) res |= (1ll << j);
            if(nxt[v][yj] != -1 && cnt[nxt[v][yj]] > 0) {
                v = nxt[v][yj];
            }else {
                ok = 0;
                break;
            }
        }
        if(!ok) continue;
        {
            int xj = (1ll << i) & xr ? 1 : 0;
            int yj = 1;
            yj ^= xj;
            if(yj) res |= (1ll << i);
            if(nxt[v][yj] != -1 && cnt[nxt[v][yj]] > 0) { v = nxt[v][yj]; }
            else continue;
        }
        for(int j = i - 1;j >= 0;j--) {
            int xj = (1ll << j) & xr ? 1 : 0;
            if(nxt[v][xj] != -1 && cnt[nxt[v][xj]] > 0) {
                if(xj) res |= (1ll << j);
                v = nxt[v][xj];
            }else if(nxt[v][xj ^ 1] != -1 && cnt[nxt[v][xj ^ 1]] > 0) {
                if(!xj) res |= (1ll << j);
                v = nxt[v][xj ^ 1];
            }else {
                ok = 0;
                break;
            }
        }
        if(ok) return res;
    }
    return -1;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    fill((int*)nxt, (int*)nxt + N * LOG, -1);

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%lld", &b[i]);
        add(b[i]);
    }

    ll last = 0;
    ll xr = 0;

    vec< ll > res;

    for(int i = 1;i <= n;i++) {
        ll bi = get_min(xr, last);
        if(bi == -1) {
            puts("No");
            return 0;
        }
        del(bi);
        res.push_back(bi);
        xr ^= bi;
        last ^= bi;
    }

    puts("Yes");

    for(ll x : res) {
        printf("%lld ", x);
    }

    puts("");

    return 0;
}