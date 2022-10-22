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

double const pi = acos(-1.0);

struct pt {
    int x, y;
    pt() : x(0), y(0) { }
    pt(int _x, int _y) : x(_x), y(_y) { }
    ll dist(pt const & other) const {
        return 1ll * (x - other.x) * (x - other.x) + 1ll * (y - other.y) * (y - other.y);
    }
    void read() {
        scanf("%d %d", &x, &y);
    }
};

int const N = 1005;

int n;
pt c[N];
int r[N];
vec< int > g[N];
int h[N];
bool used[N];
int color[N];

void dfs(int v, int H = 0) {
    used[v] = 1;
    h[v] = H;
    color[v] = H % 2;
    for(int to : g[v]) {
        dfs(to, H + 1);
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        c[i].read();
        scanf("%d", &r[i]);
    }

    ll res = 0;

    for(int i = 1;i <= n;i++) {
        g[i].clear();
        color[i] = 0;
        used[i] = 0;
    }
    for(int i = 1;i <= n;i++) {
        int par = -1;
        for(int j = 1;j <= n;j++) {
            if(i == j) continue;
            if(r[j] <= r[i]) continue;
            if(c[i].dist(c[j]) <= 1ll * (r[j] - r[i]) * (r[j] - r[i])) {
                if(par == -1 || r[par] > r[j]) {
                    par = j;
                }
            }
        }
        if(par != -1) {
            g[par].push_back(i);
        }
    }

    for(int i = 1;i <= n;i++) {
        if(!used[i]) {
            dfs(i);
        }
    }

    for(int i = 1;i <= n;i++) {
        h[i] = max(0, h[i] - 1);
        color[i] = h[i] % 2;
    }

    for(int i = 1;i <= n;i++) {
        if(color[i]) {
            res -= 1ll * r[i] * r[i];
        }else {
            res += 1ll * r[i] * r[i];
        }
    }

    cout.precision(10);
    cout << fixed << (long double)pi * (long double)res << "\n";

    return 0;
}