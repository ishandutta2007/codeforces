#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1005;

char a[N][N];
int n, m;
pii s, t;
int dist[N][N][4];

int main() {

    scanf("%d %d", &n, &m);

    for(int i = 0;i < n;i++) {
        scanf("%s", a[i]);
        for(int j = 0;j < m;j++) {
            if(a[i][j] == 'S') {
                s = make_pair(i, j);
            }
            if(a[i][j] == 'T') {
                t = make_pair(i, j);
            }
        }
    }

    for(int i = 0;i < n;i++) {
        for(int j = 0;j < m;j++) {
            for(int x = 0;x < 4;x++) {
                dist[i][j][x] = inf;
            }
        }
    }

    deque< pair< pii, int > > q;

    for(int x = 0;x < 4;x++) {
        dist[s.first][s.second][x] = 0;
        q.push_back(make_pair(s, x));
    }

    pii D[4] = {
        {-1, 0},
        {0, 1},
        {1, 0},
        {0, -1}
    };

    while(!q.empty()) {
        pii v;
        int way;
        tie(v, way) = q.front();
        q.pop_front();
        for(int dty = -1;dty <= 1;dty++) {
            int ty = ((way + dty) % 4 + 4) % 4;
            pii to = make_pair(v.first + D[ty].first, v.second + D[ty].second);
            if(to.first < 0 || to.first >= n || to.second < 0 || to.second >= m) continue;
            if(a[to.first][to.second] == '*') continue;
            int weight = dty != 0;
            if(dist[to.first][to.second][ty] > dist[v.first][v.second][way] + weight) {
                dist[to.first][to.second][ty] = dist[v.first][v.second][way] + weight;
                if(weight) {
                    q.push_back(make_pair(to, ty));
                }else {
                    q.push_front(make_pair(to, ty));
                }
            }
        }
    }

    for(int x = 0;x < 4;x++) {
        if(dist[t.first][t.second][x] <= 2) {
            printf("YES\n");
            return 0;
        }
    }

    printf("NO\n");

    return 0;
}