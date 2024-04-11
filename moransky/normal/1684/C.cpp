// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2e5 + 5;

int n, m, d[N], t;

vector<int> a[N];

bool vis[N];


int sp = 0, la;

void inline db(int x, int o) {
    if (x < 1 || x >= m) return;
    for (int i = 1; i <= n; i++)
        if (a[i][x] > a[i][x + 1]) la += -o; 
}

bool inline chk(int x, int y) {
    if (x == y) return 0;
    if (x > y) swap(x, y);
    la = sp;
    db(x - 1, 1), db(x, 1);
     if (x != y - 1) db(y - 1, 1);
      db(y, 1);
    for (int i = 1; i <= n; i++)
        swap(a[i][x], a[i][y]);
    
    db(x - 1, -1), db(x, -1);
    if (x != y - 1)  db(y - 1, -1);
     db(y, -1);
    for (int i = 1; i <= n; i++)
        swap(a[i][x], a[i][y]);
    return la == 0;
}


void inline work() {
    if (t > 6) {
        puts("-1");
        return;
    }
    if (t == 0) {
        puts("1 1");
        return ;
    }
    for (int i = 1; i <= t; i++)
        for (int j = 1; j <= m; j++)
            if (chk(d[i], j)) {
                printf("%d %d\n",  d[i], j);
                return;
            }
    puts("-1");
}


int main() {
    int T; read(T);
    while (T--) {
        sp = 0;
        read(n); read(m);
        for (int i = 1; i <= n; i++) {
            a[i].clear();
            a[i].pb(0);
            for (int j = 1; j <= m; j++) {
                int x; read(x);
                a[i].pb(x);
            }
            for (int j = 2; j <= m; j++) {
                if (a[i][j - 1] > a[i][j]) vis[j - 1] = 1, vis[j] = 1, sp++;
            }
        }

        t = 0;
        for (int i = 1; i <= m; i++) {
            if (vis[i]) d[++t] = i;
        }

        work();

        for (int i = 1; i <= n; i++) {
            a[i].clear();
        }
        for (int i = 1; i <= m; i++) vis[i] = 0;
    }
    return 0;
}