#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int , int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int n, m, k;
ll h;
vec< ll > a, edge;
vec< int > c;
vec< char > del;

set< pair< ll, int > > H[2];

void rebuild() {
    vec< ll > dist(k, inf64);
    dist[0] = 0;
    set< pair< ll, int > > q;
    q.insert({0ll, 0});
    while(!q.empty()) {
        int v = q.begin()->second;
        q.erase(q.begin());
        for(int to, i = 0;i < (int)edge.size();i++) {
            to = (v + edge[i]) % k;
            if(dist[to] > dist[v] + edge[i]) {
                q.erase({dist[to], to});
                dist[to] = dist[v] + edge[i];
                q.insert({dist[to], to});
            }
        }
    }
    H[0].clear();
    H[1].clear();
    for(int i = 0;i < n;i++) {
        if(del[i]) continue;
        if(dist[a[i] % k] <= a[i])
            H[1].insert({c[i], -i});
        else
            H[0].insert({c[i], -i});
    }
}

bool solve() {

    scanf("%I64d %d %d %d", &h, &n, &m, &k);

    a.resize(n);
    c.resize(n);
    del.resize(n);

    for(int i = 0;i < n;i++) {
        scanf("%I64d %d", &a[i], &c[i]);
        a[i]--;
    }

    rebuild();

    for(int type, i = 0;i < m;i++) {
        scanf("%d", &type);
        if(type == 1) {
            ll x;
            scanf("%I64d", &x);
            edge.push_back(x);
            rebuild();
        }else if(type == 2) {
            int x, y;
            scanf("%d %d", &x, &y);
            x--;
            if(H[0].count({c[x], -x})) {
                H[0].erase({c[x], -x});
                c[x] -= y;
                H[0].insert({c[x], -x});
            }else {
                H[1].erase({c[x], -x});
                c[x] -= y;
                H[1].insert({c[x], -x});
            }
        }else {
            if(H[1].empty()) printf("0\n");
            else {
                int v = -(--H[1].end())->second;
                H[1].erase(--H[1].end());
                del[v] = 1;
                printf("%d\n", c[v]);
            }
        }
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}