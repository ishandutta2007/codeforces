#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXN = 105;

int n, d;
int a[MAXN], x[MAXN], y[MAXN], dist[MAXN][MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d %d", &n, &d);
    for (int i=1; i<n-1; i++) scanf("%d", &a[i]);
    for (int i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i == j) continue;
            dist[i][j] = d*(abs(x[i] - x[j]) + abs(y[i] - y[j])) - a[j];
        }
    }
    for (int k=0; k<n; k++) {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    printf("%d\n", dist[0][n-1]);
}