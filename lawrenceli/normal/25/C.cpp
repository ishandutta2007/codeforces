#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 305;

int n, K;
ll d[MAXN][MAXN];

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%I64d", &d[i][j]);
        }
    }
    scanf("%d", &K);
    for (int i=0; i<K; i++) {
        int a, b;
        ll c;
        scanf("%d %d %I64d", &a, &b, &c);
        a--; b--;
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                d[j][k] = d[k][j] = min(d[j][k], d[j][a] + c + d[b][k]);
                d[j][k] = d[k][j] = min(d[j][k], d[j][b] + c + d[a][k]);
            }
        }
        ll sum = 0;
        for (int j=0; j<n; j++) {
            for (int k=j+1; k<n; k++) {
                sum += d[j][k];
            }
        }
        printf("%I64d ", sum);
    }
}