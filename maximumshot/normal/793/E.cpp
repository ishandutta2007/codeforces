#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5005;

int n;
int a, b, c, d;
int p[N];
vec< int > g[N];
bool used[N];
int sz[N];

void dfs(int v) {
    sz[v] = g[v].empty();
    for(int to : g[v]) {
        dfs(to);
        sz[v] += sz[to];
    }
}

bool check(vec< int > arr, int need) {
    if(need < 0) return false;
    vec< char > dp(need + 1);
    dp[0] = 1;
    for(int x : arr) {
        for(int y = need;y >= x;y--) {
            dp[y] |= dp[y - x];
        }
    }
    return dp[need];
}

int main() {

    scanf("%d", &n);
    scanf("%d %d %d %d", &a, &b, &c, &d);

    for(int i = 2;i <= n;i++) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
    }

    dfs(1);

    if(sz[1] % 2) {
        puts("NO");
        return 0;
    }

    used[a] = used[b] = used[c] = used[d] = 1;

    vec< int > m1, m2;

    int sza, szb, szc, szd;

    sza = szb = szc = szd = 1;

    for(int v = p[a], to = a;v > 1;to = v, v = p[v]) {
        used[v] = 1;
        sza = sz[v];
        for(int u : g[v]) {
            if(u == to) continue;
            m1.push_back(sz[u]);
        }
    }

    for(int v = p[b], to = b;v > 1;to = v, v = p[v]) {
        used[v] = 1;
        szb = sz[v];
        for(int u : g[v]) {
            if(u == to) continue;
            m1.push_back(sz[u]);
        }
    }

    for(int v = p[c], to = c;v > 1;to = v, v = p[v]) {
        used[v] = 1;
        szc = sz[v];
        for(int u : g[v]) {
            if(u == to) continue;
            m2.push_back(sz[u]);
        }
    }

    for(int v = p[d], to = d;v > 1;to = v, v = p[v]) {
        used[v] = 1;
        szd = sz[v];
        for(int u : g[v]) {
            if(u == to) continue;
            m2.push_back(sz[u]);
        }
    }

    for(int to : g[1]) {
        if(used[to]) continue;
        m1.push_back(sz[to]);
        m2.push_back(sz[to]);
    }

    if(check(m1, sz[1] / 2 - 1 - szc) && check(m2, sz[1] / 2 - 1 - szb)) {
        puts("YES");
    }else {
        puts("NO");
    }

    return 0;
}