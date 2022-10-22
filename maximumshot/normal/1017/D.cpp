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

const int N = 12;
const int M = 5e5 + 5;

char buffer[20];
int n, m, q;

inline int read_mask() {
    scanf("%s", buffer);
    int res = 0;
    for(int i = 0;i < n;i++) {
        if(buffer[i] == '1') {
            res |= (1 << i);
        }
    }
    return res;
}

int w[N];
int cost[1 << N];
int a[M];
int cnt[1 << N];
int mem[1 << N][105];

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &q);

    for(int i = 0;i < n;i++) {
        scanf("%d", &w[i]);
    }

    for(int i = 0;i < m;i++) {
        a[i] = read_mask();
        cnt[a[i]]++;
    }

    int _2n = 1 << n;
    int biggest = _2n - 1;

    for(int mask = 0;mask < _2n;mask++) {
        for(int i = 0;i < n;i++) {
            if((1 << i) & mask) {
                cost[mask] += w[i];
            }
        }
        if(cost[mask] >= 105) cost[mask] = 104;
    }

    for(int mask = 0;mask < _2n;mask++) {
        for(int sub = 0;sub < _2n;sub++) {
            mem[mask][ cost[ mask ^ sub ^ biggest ] ] += cnt[sub];
        }
        for(int x = 1;x < 105;x++) {
            mem[mask][x] += mem[mask][x - 1];
        }
    }

    for(int iter = 0;iter < q;iter++) {
        int mask = read_mask();
        int k;
        scanf("%d", &k);
        printf("%d\n", mem[mask][k]);
    }

    return 0;
}