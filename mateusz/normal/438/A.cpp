#include <bits/stdc++.h>

using namespace std;
const int N = 1005;
int cost[N];
int n, m, a, b;
int main() {
    int suma = 0;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &cost[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d %d", &a, &b);
        suma += min(cost[a], cost[b]);
    }
    printf("%d\n", suma);
    return 0;
}