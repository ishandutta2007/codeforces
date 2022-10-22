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

int const N = 1005;

int n, m;
int a[N][N];
int d[N][N];

int get(int li, int lj, int ri, int rj) {
    if(li > ri || lj > rj) return 0;
    return d[ri][rj] - d[li - 1][rj] - d[ri][lj - 1] + d[li - 1][lj - 1];
}

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            scanf("%d", &a[i][j]);
            d[i][j] = a[i][j] + d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
        }
    }

    int res = 0;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j]) continue;
            if(get(1, j, i, j)) res++;
            if(get(i, j, n, j)) res++;
            if(get(i, 1, i, j)) res++;
            if(get(i, j, i, m)) res++;
        }
    }

    printf("%d\n", res);

    return 0;
}