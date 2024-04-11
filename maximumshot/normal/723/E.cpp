#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

void solve() {
    int n, m;
    scanf("%d %d", &n, &m);
    vec< vec< int > > g(n, vec< int >(n));
    vec< vec< char > > realy(n, vec< char >(n));
    vec< int > deg(n);
    for(int u, v, i = 0;i < m;i++) {
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u][v]++;
        g[v][u]++;
        realy[u][v] = realy[v][u] = 1;
        deg[u]++;
        deg[v]++;
    }
    int res = 0;
    for(int i = 0;i < n;i++) {
        if(deg[i] % 2 == 0) res++;
    }
    printf("%d\n", res);
    for(int i = 0;i < n;i++) {
        if(deg[i] % 2 == 0) continue;
        for(int j = i + 1;j < n;j++) {
            if(deg[j] % 2 == 0) continue;
            g[i][j]++;
            g[j][i]++;
            deg[i]++;
            deg[j]++;
            break;
        }
    }
    vec< char > used(n);
    vec< vec< char > > say(n, vec< char >(n));
    for(int i = 0;i < n;i++) {
        if(used[i]) continue;

        {
            queue< int > q;
            q.push(i);
            used[i] = 1;
            while(!q.empty()) {
                int v = q.front();
                //cout << v << ' ';
                q.pop();
                for(int to = 0;to < n;to++) {
                    if(g[v][to] && !used[to]) {
                        used[to] = 1;
                        q.push(to);
                    }
                }
            }

            //cout << '\n';
        }

        vec< int > st;
        int last = -1;
        int first = -1;
        st.push_back(i);
        while(!st.empty()) {
            int v = st.back();
            int j = 0; while(j < n && !g[v][j]) j++;
            if(j == n) {
                if(first == -1) first = v;
                if(last != -1 && realy[last][v] && !say[last][v]) {
                    printf("%d %d\n", last + 1, v + 1);
                    say[last][v] = say[v][last] = 1;
                }
                last = v;
                st.pop_back();
            }else {
                g[v][j]--;
                g[j][v]--;
                st.push_back(j);
            }
        }
        if(first != -1 && last != -1 && realy[last][first] && !say[last][first]) {
            printf("%d %d\n", last + 1, first + 1);
            say[last][first] = say[first][last] = 1;
        }
        for(int u = 0;u < n;u++) {
            for(int v = u + 1;v < n;v++) {
                if(used[u] && used[v] && realy[u][v] && !say[u][v]) {
                    printf("%d %d\n", u + 1, v + 1);
                    say[u][v] = say[v][u] = 1;
                }
            }
        }
    }
}

int main() {

    int t;
    scanf("%d", &t);

    while(t--) {
        solve();
    }

    return 0;
}