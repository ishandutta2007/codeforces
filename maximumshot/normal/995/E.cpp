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

inline int _sum(int a, int b, int mod) {
    return a + b < mod ? a + b : a + b - mod;
}

inline int _sub(int a, int b, int mod) {
    return a >= b ? a - b : a - b + mod;
}

inline int _mul(int a, int b, int mod) {
    return (1ll * a * b) % mod;
}

inline int _binpow(int x, int pw, int mod) {
    int res = 1;
    int tmp = x;
    while(pw > 0) {
        if(pw & 1) {
            res = _mul(res, tmp, mod);
        }
        tmp = _mul(tmp, tmp, mod);
        pw >>= 1;
    }
    return res;
}

inline int _rev(int x, int mod) {
    return _binpow(x, mod - 2, mod);
}

const int ITER = 5e4 + 5;

void gen_ways(vec< int > *way, int s, int p) {
    for(int iter = 0;iter < ITER;iter++) {
        int x = s;
        for(int j = 0;j < 100;j++) {
            way[iter].push_back(x);
            int ty = rand() % 3;
            if(ty == 0) {
                x = _sum(x, 1, p);
            }else if(ty == 1) {
                x = _sub(x, 1, p);
            }else {
                x = _rev(x, p);
            }
        }
    }
}

void print(vec< int > *wa, vec< int > *wb, int i, int j, int both, int p) {
    int si = 0;
    int sj = 0;
    while(wa[i][si] != both) si++;
    while(wb[j][sj] != both) sj++;
    vec< int > way;
    for(int q = 0;q <= si;q++) way.push_back(wa[i][q]);
    for(int q = sj - 1;q >= 0;q--) way.push_back(wb[j][q]);
    printf("%d\n", (int)way.size() - 1);
    for(int q = 0;q + 1 < (int)way.size();q++) {
        int now = way[q];
        int nxt = way[q + 1];
        if(_sum(now, 1, p) == nxt) {
            printf("1 ");
        }else if(_sub(now, 1, p) == nxt) {
            printf("2 ");
        }else {
            printf("3 ");
        }
    }
    printf("\n");
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int u, v, p;

    scanf("%d %d %d", &u, &v, &p);

    if(u == v) {
        puts("0");
        return 0;
    }

    vec< int > wa[ITER], wb[ITER];

    gen_ways(wa, u, p);
    gen_ways(wb, v, p);

    unordered_map< int, int > um;

    for(int iter = 0;iter < ITER;iter++) {
        for(int j = 0;j < (int)wa[iter].size();j++) {
            um[wa[iter][j]] = iter;
        }
    }

    for(int iter = 0;iter < ITER;iter++) {
        for(int j = 0;j < (int)wb[iter].size();j++) {
            if(!um.count(wb[iter][j])) continue;
            print(wa, wb, um[wb[iter][j]], iter, wb[iter][j], p);
            return 0;
        }
    }

    return 0;
}