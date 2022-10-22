#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;
const double pi = acos(-1.0);

const int N = 1e5 + 5;

int n;
int p[N];
vec< int > g[N];
int cnt[N];

void dfs(int v, int d = 0) {
    if((int)g[v].size() & 1) {
        cnt[d + 1] ^= 1;
    }
    for(int to : g[v]) {
        dfs(to, d + 1);
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 2;i <= n;i++) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
    }

    cnt[0] = 1;

    dfs(1);

    int res = 0;

    for(int i = 0;i < N;i++) {
        res += cnt[i];
    }

    printf("%d\n", res);

    return 0;
}