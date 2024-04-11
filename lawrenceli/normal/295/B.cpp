#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 505;

int n, dist[MAXN][MAXN], x[MAXN];
ll ans[MAXN];
bool in[MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d", &dist[i][j]);
        }
    }
    for (int i=0; i<n; i++) in[i] = 1;
    for (int i=0; i<n; i++) {
        scanf("%d", &x[i]);
        x[i]--; in[x[i]] = 0;
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!in[k] || !in[i] || !in[j]) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    for (int i=n-1; i>=0; i--) {
        in[x[i]] = 1;
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                dist[j][k] = min(dist[j][k], dist[j][x[i]] + dist[x[i]][k]);
            }
        }
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                if (!in[j] || !in[k]) continue;
                ans[i] += dist[j][k];
            }
        }
    }
    for (int i=0; i<n; i++) printf("%I64d ", ans[i]);
}