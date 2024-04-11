#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e6 + 5;

vec< int > g[N];
int n, m;
int deg[N];
bool have[N];

bool checkConnected() {
    queue< int > q;
    vec< char > used(n + 1);
    int start = 1;
    while(!have[start]) start++;
    q.push(start);
    used[start] = 1;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int to : g[v]) {
            if(!used[to]) {
                used[to] = 1;
                q.push(to);
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        if(have[i] && !used[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {

    scanf("%d %d", &n, &m);

    int cnt = 0;

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        have[u] = 1;
        have[v] = 1;
        if(u != v) {
            deg[u]++;
            deg[v]++;
        }else {
            cnt++;
        }
    }

    if(!checkConnected()) {
        puts("0");
        return 0;
    }else {
        ll res = 0;
        for(int i = 1;i <= n;i++) {
            res += 1ll * deg[i] * (deg[i] - 1) / 2;
        }
        res += 1ll * cnt * (m - cnt) + 1ll * cnt * (cnt - 1) / 2;
        cout << res << "\n";
    }

    return 0;
}