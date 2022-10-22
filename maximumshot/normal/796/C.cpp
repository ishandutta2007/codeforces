#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 3e5 + 5;

int n;
int a[N];
vec< int > g[N];

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int res = INT_MAX;

    multiset< int > q;

    for(int i = 1;i <= n;i++) {
        q.insert(a[i]);
    }

    for(int s = 1;s <= n;s++) {
        int tmp = a[s];
        q.erase(q.lower_bound(a[s]));
        for(int to : g[s]) {
            tmp = max(tmp, a[to] + 1);
            q.erase(q.lower_bound(a[to]));
        }
        if(!q.empty()) {
            tmp = max(tmp, *(--q.end()) + 2);
        }
        q.insert(a[s]);
        for(int to : g[s]) {
            q.insert(a[to]);
        }
        res = min(res, tmp);
    }

    printf("%d\n", res);

    return 0;
}