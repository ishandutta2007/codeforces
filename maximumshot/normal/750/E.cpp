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

int const N = 200005;

int n, q;
char s[N];

struct Node {
   int dp[5][5];
   Node() {
       for(int i = 0;i < 5;i++) {
           for(int j = 0;j < 5;j++) {
               dp[i][j] = inf;
           }
       }
   }
} t[4 * N];

Node merge(Node const & l, Node const & r) {
    Node res;
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 5;j++) {
            for(int k = i;k <= j;k++) {
                res.dp[i][j] = min(res.dp[i][j], l.dp[i][k] + r.dp[k][j]);
            }
        }
    }
    return res;
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        for(int i = 0;i < 5;i++) t[v].dp[i][i] = 0;
        if(s[tl] == '2') {
            t[v].dp[0][0] = 1;
            t[v].dp[0][1] = 0;
        }else if(s[tl] == '0') {
            t[v].dp[1][1] = 1;
            t[v].dp[1][2] = 0;
        }else if(s[tl] == '1') {
            t[v].dp[2][2] = 1;
            t[v].dp[2][3] = 0;
        }else if(s[tl] == '6') {
            t[v].dp[3][3] = 1;
            t[v].dp[4][4] = 1;
        }else if(s[tl] == '7') {
            t[v].dp[3][4] = 0;
        }
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        t[v] = merge(t[v << 1], t[v << 1 | 1]);
    }
}

Node get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return t[v];
    }else {
        int tm = (tl + tr) >> 1;
        if(l <= tm) {
            if(r > tm) {
                return merge(
                    get(v << 1, tl, tm, l, r),
                    get(v << 1 | 1, tm + 1, tr, l, r)
                );
            }else return get(v << 1, tl, tm, l, r);
        }else return get(v << 1 | 1, tm + 1, tr, l, r);
    }
}

int main() {

    scanf("%d %d %s", &n, &q, s + 1);

    build(1, 1, n);

    Node res;

    for(int x, l, r, i = 0;i < q;i++) {
        scanf("%d %d", &l, &r);
        res = get(1, 1, n, l, r);
        x = res.dp[0][4];
        printf("%d\n", x == inf ? -1 : x);
    }

    return 0;
}