#include <bits/stdc++.h>

using namespace std;

const int N = 100005;

int n, m;
int a[N], b[N];

int main() {
    
    scanf("%d %d", &n, &m);
    
    int best = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &b[i]);
        if (a[i] * b[best] < a[best] * b[i]) {
            best = i;
        }
    }
    
    long double ans = (long double)m * a[best] / b[best];
    printf("%.10Lf\n", ans);
    
    return 0;
}