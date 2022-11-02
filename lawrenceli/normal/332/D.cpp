#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

typedef long double ld;
typedef long long ll;

const int MAXN = 2005;

int n, k, adj[MAXN][MAXN];
ll tot, memo[MAXN][MAXN];
ld ans;

ll C(int x, int y) {
    if (memo[x][y] != -1) return memo[x][y];
    if (x < y) return 0;
    ll ret = 1;
    vector<int> v;
    for (int i=x-y+1; i<=x; i++) v.push_back(i);
    for (int i=1; i<=y; i++) {
        for (int j=0; j<v.size(); j++) {
            if (v[j] % i == 0) {
                v[j] /= i; break;
            }
        }
    }
    for (int i=0; i<v.size(); i++) ret *= v[i];
    return memo[x][y] = ret;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &k);
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            adj[i][j] = -1;
    for (int i=0; i<MAXN; i++)
        for (int j=0; j<MAXN; j++)
            memo[i][j] = -1;
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            scanf("%d", &adj[i][j]);
            adj[j][i] = adj[i][j];
        }
    }
    for (int i=0; i<n; i++) {
        int num = 0;
        for (int j=0; j<n; j++) {
            if (adj[i][j] != -1) num++;
        }
        tot += C(num, k);
    }
    for (int i=0; i<n; i++) {
        int num = 0;
        for (int j=0; j<n; j++) {
            if (adj[i][j] != -1) num++;
        }
        for (int j=0; j<n; j++) {
            if (adj[i][j] != -1) {
                ans += ld(C(num-1, k-1)) / tot * adj[i][j];
            }
        }
    }
    ll lans = ll(ans);
    if (abs(lans + 1 - ans) < 1e-6) printf("%I64d\n", lans + 1);
    else printf("%I64d\n", lans);
}