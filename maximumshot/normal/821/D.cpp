#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e4 + 5;

int n, m, k;
short who[N][N];
pii pts[N];
vec< int > str[N];
vec< int > col[N];
int color[N];
int cur = 1;

void mark() {
    for(int i = 1;i <= k;i++) {
        if(color[i]) continue;
        queue< int > q;
        q.push(i);
        color[i] = cur;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            for(int dx = -1;dx <= 1;dx++) {
                for(int dy = -1;dy <= 1;dy++) {
                    if(dx == 0 && dy == 0) continue;
                    if(dx != 0 && dy != 0) continue;
                    int tox = pts[v].first + dx;
                    int toy = pts[v].second + dy;
                    if(tox < 1 || tox > n || toy < 1 || toy > m) continue;
                    int to = who[tox][toy];
                    if(to == 0) continue;
                    if(!color[to]) {
                        color[to] = cur;
                        q.push(to);
                    }
                }
            }
        }
        cur++;
    }
}

int dist[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d %d", &n, &m, &k);

    for(int r, c, i = 1;i <= k;i++) {
        scanf("%d %d", &r, &c);
        pts[i] = make_pair(r, c);
        str[r].push_back(i);
        col[c].push_back(i);
        who[r][c] = i;
    }

    mark();

    cur--;

    // 1 .. cur

    for(int i = 1;i <= k;i++) {
        dist[i] = inf;
    }

    dist[who[1][1]] = 0;

    deque< int > que;

    que.push_back(who[1][1]);

    while(!que.empty()) {
        int di, v = que.front(), lx, ly, rx, ry;
        que.pop_front();
        lx = max(1, pts[v].first - 2);
        rx = min(n, pts[v].first + 2);
        ly = max(1, pts[v].second - 2);
        ry = min(m, pts[v].second + 2);
        for(int x = lx;x <= rx;x++) {
            for(int to : str[x]) {
                di = color[v] != color[to];
                if(dist[to] > dist[v] + di) {
                    dist[to] = dist[v] + di;
                    if(di == 1) {
                        que.push_back(to);
                    }else {
                        que.push_front(to);
                    }
                }
            }
        }
        for(int y = ly;y <= ry;y++) {
            for(int to : col[y]) {
                di = color[v] != color[to];
                if(dist[to] > dist[v] + di) {
                    dist[to] = dist[v] + di;
                    if(di == 1) {
                        que.push_back(to);
                    }else {
                        que.push_front(to);
                    }
                }
            }
        }
    }

    int res = inf;

    for(int i = 1;i <= k;i++) {
        if(abs(pts[i].first - n) <= 1 || abs(pts[i].second - m) <= 1) {
            if(pts[i].first == n && pts[i].second == m) {
                res = min(res, dist[i]);
            }else {
                res = min(res, dist[i] + 1);
            }
        }
    }

    printf("%d\n", res == inf ? -1 : res);

    return 0;
}