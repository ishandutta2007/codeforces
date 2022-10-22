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

int n, k, d;
vec< int > g[N];
bool p[N];
int from[N];

int main() {

    scanf("%d %d %d", &n, &k, &d);

    for(int i = 1;i <= n;i++) {
        from[i] = -1;
    }

    queue< int > q;

    for(int x, i = 1;i <= k;i++) {
        scanf("%d", &x);
        p[x] = 1;
    }

    for(int i = 1;i <= n;i++) {
        if(!p[i]) continue;
        q.push(i);
        from[i] = i;
    }

    map< pii, int > id;

    for(int u, v, i = 1;i < n;i++) {
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
        if(u > v) {
            swap(u, v);
        }
        id[make_pair(u, v)] = i;
    }

    vec< pii > result;

    while(!q.empty()) {
        int v = q.front();
        q.pop();
//        cout << v << "\n";
        for(int to : g[v]) {
            if(from[to] == -1) {
                from[to] = from[v];
                q.push(to);
            }else {
                if(from[to] != from[v]) {
                    result.push_back(make_pair(min(v, to), max(v, to)));
                }
            }
        }
    }

    sort(ALL(result));
    result.resize(unique(ALL(result)) - result.begin());

    printf("%d\n", (int)result.size());

    for(pii t : result) {
        printf("%d ", id[t]);
    }
    printf("\n");

    return 0;
}

/*
7 2 4
1 7
1 2
2 3
3 4
4 5
5 6
5 7
*/