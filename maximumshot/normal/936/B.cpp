#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

int n, m, s;
vec< int > g[N];
vec< int > gr[N];
int tops[N];
int used[N];
int cnt[N];
int comp[N];
int sz;
int cur;

void dfs1(int v) {
    used[v] = 1;
    for(int to : g[v]) {
        if(!used[to]) {
            dfs1(to);
        }
    }
    tops[sz++] = v;
}

void dfs2(int v) {
    comp[v] = cur;
    cnt[cur]++;
    for(int to : gr[v]) {
        if(!comp[to]) {
            dfs2(to);
        }
    }
}

int dp[N][2];
int fr[N][2];

void can_win() {
    queue< pii > q;
    for(int v = 1;v <= n;v++) {
        if(g[v].empty()) {
            dp[v][0] = 1;
            q.push(make_pair(v, 0));
        }
    }
    while(!q.empty()) {
        int v, t;
        tie(v, t) = q.front();
        q.pop();
        for(int to : gr[v]) {
            if(!dp[to][t ^ 1]) {
                dp[to][t ^ 1] = 1;
                fr[to][t ^ 1] = v;
                q.push(make_pair(to, t ^ 1));
            }
        }
    }
//    for(int v = 1;v <= n;v++) {
//        cout << v << " : " << dp[v][0] << " " << dp[v][1] << "\n";
//    }
    if(!dp[s][1]) {
        return;
    }
    puts("Win");
    for(int v = s, t = 1;;v = fr[v][t], t ^= 1) {
        printf("%d ", v);
        if(g[v].empty()) break;
    }
    puts("");
    exit(0);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int v = 1;v <= n;v++) {
        int tsz;
        scanf("%d", &tsz);
        for(int u, j = 0;j < tsz;j++) {
            scanf("%d", &u);
            g[v].push_back(u);
            gr[u].push_back(v);
        }
    }

    scanf("%d", &s);

    for(int v = 1;v <= n;v++) {
        if(!used[v]) {
            dfs1(v);
        }
    }

    reverse(tops, tops + sz);

    for(int i = 0;i < sz;i++) {
        int v = tops[i];
        if(!comp[v]) {
            cur++;
            dfs2(v);
        }
    }

    fill(used, used + N, 0);

    {
        queue< int > q;
        for(int v = 1;v <= n;v++) {
            if(cnt[comp[v]] > 1) {
                used[v] = 1;
                q.push(v);
            }
        }
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int to : gr[v]) {
                if(!used[to]) {
                    used[to] = 1;
                    q.push(to);
                }
            }
        }
    }

    int can_draw = used[s];

    can_win();

    if(can_draw) {
        puts("Draw");
    }else {
        puts("Lose");
    }

    return 0;
}