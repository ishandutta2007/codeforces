#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 5005;

int n, b;
int c[N];
int d[N];
vec< int > g[N];

inline int Sum(int x, int y) {
    return min(b + 1, x + y);
}

pair< vec< int >, vec< int > > dfs(int v) {
    vec< int > a0(1), a1(1);
    a0[0] = 0;
    a1[0] = 0;
    for(int to : g[v]) {
        vec< int > b0, b1;
        tie(b0, b1) = dfs(to);

        if(a0.size() < b0.size()) swap(a0, b0);
        if(a1.size() < b1.size()) swap(a1, b1);

        int s0 = (int)a0.size();
        int s1 = (int)a1.size();

        while(a0.size() < s0 + b0.size()) a0.push_back(b + 1);
        while(a1.size() < s1 + b1.size()) a1.push_back(b + 1);

        for(int i = (int)a0.size() - 1;i >= 0;i--) {
            for(int j = 0;j < (int)b0.size() && j <= i;j++) {
                a0[i] = min(a0[i], Sum(a0[i - j], b0[j]));
            }
        }

        for(int i = (int)a1.size() - 1;i >= 0;i--) {
            for(int j = 0;j < (int)b1.size() && j <= i;j++) {
                a1[i] = min(a1[i], Sum(a1[i - j], b1[j]));
            }
        }
    }

    a1.push_back(b + 1);

    for(int i = (int)a1.size() - 2;i >= 0;i--) {
        a1[i + 1] = Sum(a1[i], min(b + 1, c[v] - d[v]));
    }

    a0.push_back(b + 1);

    for(int i = (int)a0.size() - 1;i > 0;i--) {
        a0[i] = min(a0[i], Sum(a0[i - 1], min(b + 1, c[v])));
    }

    while(a1.size() < a0.size()) a1.push_back(b + 1);
    while(a0.size() < a1.size()) a0.push_back(b + 1);

    for(int i = 0;i < (int)a1.size();i++) {
        a1[i] = min(a1[i], a0[i]);
    }

    while(a0.back() == b + 1) a0.pop_back();
    while(a1.back() == b + 1) a1.pop_back();

//    cout << v << " : ";

//    for(int x : a0) cout << x << " ";
//    cout << " | ";
//    for(int x : a1) cout << x << " ";
//    cout << "\n";

    return make_pair(a0, a1);
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &b);

    for(int x, i = 1;i <= n;i++) {
        scanf("%d %d", &c[i], &d[i]);
        if(i > 1) {
            scanf("%d", &x);
            g[x].push_back(i);
        }
    }

    vec< int > dp;

    tie(ignore, dp) = dfs(1);

    int res = 0;

    for(int i = (int)dp.size() - 1;i >= 0;i--) {
        if(dp[i] <= b) {
            res = i;
            break;
        }
    }

    printf("%d\n", res);

    return 0;
}