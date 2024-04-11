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

int const N = 1e5 + 5;

int q;

int nxt[N * 31][2];
int cnt[N * 31];
int sz = 1;

void init() {
    for(int i = 0;i < N * 31;i++) {
        nxt[i][0] = nxt[i][1] = -1;
        cnt[i] = 0;
    }
}

void addValue(int value) {
    int v = 0;
    cnt[0]++;
    for(int k, i = 30;i >= 0;i--) {
        k = (value >> i) & 1;
        if(nxt[v][k] == -1) {
            nxt[v][k] = sz++;
        }
        v = nxt[v][k];
        cnt[v]++;
    }
}

void delValue(int value) {
    int v = 0;
    cnt[0]--;
    for(int k, i = 30;i >= 0;i--) {
        k = (value >> i) & 1;
        v = nxt[v][k];
        cnt[v]--;
    }
}

int getAnswer(int p, int l) {
    int xr;
    int res = 0;
    int v = 0;
    for(int i = 30;i >= 0;i--) {
        int to = -1;
        for(int j = 0;j < 2;j++) {
            xr = ((p >> i) & 1) ^ j;
            if(xr < ((l >> i) & 1)) {
                res += (nxt[v][j] == -1 ? 0 : cnt[nxt[v][j]]);
            }
        }
        for(int j = 0;j < 2;j++) {
            xr = ((p >> i) & 1) ^ j;
            if(xr == ((l >> i) & 1)) {
                to = nxt[v][j];
                break;
            }
        }
        if(to == -1) break;
        v = to;
    }
    return res;
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    init();

    scanf("%d", &q);

    for(int l, p, ty, iter = 0;iter < q;iter++) {
        scanf("%d %d", &ty, &p);
        if(ty == 1) {
            addValue(p);
        }else if(ty == 2) {
            delValue(p);
        }else {
            scanf("%d", &l);
            printf("%d\n", getAnswer(p, l));
        }
    }

    return 0;
}