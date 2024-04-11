#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 105;

int n, m;
char a[N][N];

void ask(char t, int & x, int & y) {
    printf("%c\n", t);
    fflush(stdout);
    scanf("%d %d", &x, &y);
    if(a[x][y] == 'F' || (x == -1 && y == -1)) {
        exit(0);
    }
}

int dist[N][N];
pii from[N][N];

vec< pii > darr = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int main() {

#ifdef maximumSHOT
//    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%s", a[i] + 1);
    }

    int LR = -1;
    int UD = -1;
    int x, y;

    x = y = 1;

    if(n > 1 && a[2][1] != '*') {
        ask('D', x, y);
        if(x == 1 && y == 1) {
            UD = 1;
        }else {
            UD = 0;
            ask('U', x, y);
        }
    }

    if(m > 1 && a[1][2] != '*') {
        ask('R', x, y);
        if(x == 1 && y == 1) {
            LR = 1;
        }else {
            LR = 0;
            ask('L', x, y);
        }
    }

    if(LR != -1) {
        int j = 1;
        while(j <= m && a[1][j] != '*') j++; j--;
        for(int it = 1;it <= j;it++) {
            if(a[1][it] == 'F') {
                for(int c = 2;c <= it;c++) {
                    ask(LR ? 'L' : 'R', x, y);
                }
            }
        }
        if(UD == -1) {
            for(int it = 1;it <= j;it++) {
                if(a[2][it] != '*') {
                    ask('D', x, y);
                    if(x == 1 && y == it) {
                        UD = 1;
                    }else {
                        UD = 0;
                        ask('U', x, y);
                    }
                    for(int c = it - 1;c >= 1;c--) {
                        ask(LR ? 'R' : 'L', x, y);
                    }
                    break;
                }else {
                    ask(LR ? 'L' : 'R', x, y);
                }
            }
        }
    }

    if(UD != -1) {
        int i = 1;
        while(i <= n && a[i][1] != '*') i++; i--;
        for(int it = 1;it <= i;it++) {
            if(a[it][1] == 'F') {
                for(int c = 2;c <= it;c++) {
                    ask(UD ? 'U' : 'D', x, y);
                }
            }
        }
        if(LR == -1) {
            for(int it = 1;it <= i;it++) {
                if(a[it][2] != '*') {
                    ask('R', x, y);
                    if(x == it && y == 1) {
                        LR = 1;
                    }else {
                        LR = 0;
                        ask('L', x, y);
                    }
                    for(int c = it - 1;c >= 1;c--) {
                        ask(UD ? 'D' : 'U', x, y);
                    }
                    break;
                }else {
                    ask(UD ? 'U' : 'D', x, y);
                }
            }
        }
    }

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            dist[i][j] = inf;
            from[i][j] = make_pair(-1, -1);
        }
    }

    dist[1][1] = 0;

    queue< pii > que;

    que.push(make_pair(1, 1));

    while(!que.empty()) {
        pii v = que.front(), to;
        que.pop();
        for(pii d : darr) {
            to.first = v.first + d.first;
            to.second = v.second + d.second;
            if(to.first < 1 || to.first > n || to.second < 1 || to.second > m) continue;
            if(a[to.first][to.second] == '*') continue;
            if(dist[to.first][to.second] > dist[v.first][v.second] + 1) {
                dist[to.first][to.second] = dist[v.first][v.second] + 1;
                from[to.first][to.second] = v;
                que.push(to);
            }
        }
    }

    vec< pii > way;

    pii u;

    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j] == 'F') {
                u = make_pair(i, j);
            }
        }
    }

    while(u != make_pair(-1, -1)) {
        way.push_back(u);
        u = from[u.first][u.second];
    }

    reverse(ALL(way));

    for(int i = 1;i < (int)way.size();i++) {
        u = way[i - 1];
        pii v = way[i];
        if(u.first == v.first) {
            if(u.second < v.second) {
                ask(LR ? 'L' : 'R', x, y);
            }else {
                ask(LR ? 'R' : 'L', x, y);
            }
        }else {
            if(u.first < v.first) {
                ask(UD ? 'U' : 'D', x, y);
            }else {
                ask(UD ? 'D' : 'U', x, y);
            }
        }
    }

    return 0;
}