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

int n, m;
int d[N];
pii edge[N];
vec< int > g[N];

inline int getTo(int i, int v) {
    return edge[i].first == v ? edge[i].second : edge[i].first;
}

int cnt[N];
int euler[2 * N];
int pref[2 * N];
int sz_euler;
bool used[N];
int first[N];

void dfs(int v) {
    used[v] = 1;
    for(int id : g[v]) {
        int to = getTo(id, v);
        if(used[to]) continue;
        if(first[v] == -1) first[v] = sz_euler;
        euler[sz_euler++] = id;
        dfs(to);
        if(first[to] == -1) first[to] = sz_euler;
        euler[sz_euler++] = id;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    memset(first + 1, -1, sizeof(int) * n);

    int os = -1;
    int cnt1 = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &d[i]);
        if(d[i] == -1) {
            if(os == -1) {
                os = i;
            }else {
                d[i] = 0;
            }
        }else if(d[i] == 1) {
            cnt1++;
        }
    }

    if(cnt1 % 2) {
        if(os == -1) {
            puts("-1");
            return 0;
        }else {
            d[os] = 1;
        }
    }else {
        d[os] = 0;
    }

    for(int u, v, i = 1;i <= m;i++) {
        scanf("%d %d", &u, &v);
        edge[i] = make_pair(u, v);
        g[u].push_back(i);
        g[v].push_back(i);
    }

    dfs(1);

    for(int last = -1, i = 1;i <= n;i++) {
        if(!d[i]) continue;
        if(last == -1) {
            last = i;
            continue;
        }
        pref[first[last]] ^= 1;
        pref[first[i]] ^= 1;
        last = -1;
    }

    for(int i = 0;i < sz_euler;i++) {
        if(i) pref[i] ^= pref[i - 1];
        cnt[euler[i]] ^= pref[i];
    }

    printf("%d\n", count(cnt + 1, cnt + m + 1, 1));

    for(int i = 1;i <= m;i++) {
        if(cnt[i]) {
            printf("%d\n", i);
        }
    }

    return 0;
}