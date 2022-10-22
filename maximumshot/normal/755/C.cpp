#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 10005;

int n;
int p[N];

int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if(x == y) return 0;
    if(rand() % 2) swap(x, y);
    p[y] = x;
}

int main() {

    srand(time(NULL));

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) p[i] = i;

    for(int x, i = 1;i <= n;i++) {
        scanf("%d", &x);
        merge(i, x);
    }

    int res = 0;

    for(int i = 1;i <= n;i++) res += p[i] == i;

    printf("%d\n", res);

    return 0;
}