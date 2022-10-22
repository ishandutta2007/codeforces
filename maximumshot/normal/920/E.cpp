#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned int ui;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1ll * inf * inf;

const int N = 2e5 + 5;

int n, m;
set< int > g[N];
set< int > _free;
vec< int > res;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        g[u].insert(v);
        g[v].insert(u);
    }

    for(int v = 1;v <= n;v++) {
        g[v].insert(n + 1);
    }

    for(int i = 1;i <= n;i++) {
        _free.insert(i);
    }

    for(int v = 1;v <= n;v++) {
        if(!_free.count(v)) continue;
        queue< int > q;
        q.push(v);
        _free.erase(v);
        int cnt = 1;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int last = 0;
            for(int to : g[u]) {
                // last + 1 .. to - 1
                if(last + 1 > to - 1) {
                    last = to;
                    continue;
                }
                auto fnd = _free.upper_bound(last);
                while(fnd != _free.end() && *fnd < to) {
                    q.push(*fnd);
                    fnd = _free.erase(fnd);
                    cnt++;
                }
                last = to;
            }
        }
        res.push_back(cnt);
    }

    sort(ALL(res));

    printf("%d\n", (int)res.size());

    for(int cnt : res) {
        printf("%d ", cnt);
    }

    printf("\n");

    return 0;
}