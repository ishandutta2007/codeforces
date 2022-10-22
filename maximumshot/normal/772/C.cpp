#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution (ll a, ll b, ll c, ll & x0, ll & y0, ll & g) {
    g = gcd (abs(a), abs(b), x0, y0);
    if (c % g != 0)
        return false;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0)   x0 *= -1;
    if (b < 0)   y0 *= -1;
    return true;
}

int const N = 2e5 + 5;

int n, m;
int r[N];
bool u[N];
int g[N];
int cnt[N];
int dp[N];
int from[N];
vec< int > List[N];

int main() {

    scanf("%d %d", &n, &m);

    for(int x, i = 0;i < n;i++) {
        scanf("%d", &x);
        u[x] = 1;
    }

    for(int i = 1;i < m;i++) {
        g[i] = __gcd(i, m);
        from[i] = -1;
        if(!u[i]) {
            cnt[g[i]]++;
            List[g[i]].push_back(i);
        }
    }

    dp[1] = cnt[1];

    for(int i = 1;i < N;i++) {
        for(int j = i+i;j < N;j += i) {
            if(dp[j] < dp[i] + cnt[j]) {
                dp[j] = dp[i] + cnt[j];
                from[j] = i;
            }
        }
    }

    int best = -1;

    for(int i = 1;i < m;i++) {
        if(best == -1 || dp[best] < dp[i]) {
            best = i;
        }
    }

    vec< int > way;

    while(best != -1) {
        for(int x : List[best]) {
            way.push_back(x);
        }
        best = from[best];
    }

    reverse(ALL(way));

    vec< int > res;

    if(!way.empty()) {
        res.push_back(way.front());
    }

    ll X, Y, G;

    for(int i = 1;i < (int)way.size();i++) {
        find_any_solution(way[i - 1], m, way[i], X, Y, G);
        X = (X % m + m) % m;
        res.push_back(X);
    }

    if(!u[0]) {
        res.push_back(0);
    }

    printf("%d\n", (int)res.size());

    for(int x : res) {
        printf("%d ", x);
    }
    printf("\n");

    return 0;
}