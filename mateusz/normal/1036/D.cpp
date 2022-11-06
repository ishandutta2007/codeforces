#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, m, a[N], b[N];

int main() {
    scanf("%d", &n);
    long long sumA = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        sumA += a[i];
    }
    
    scanf("%d", &m);
    long long sumB = 0;
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
        sumB += b[i];
    }
    
    if (sumA != sumB) {
        printf("-1\n");
        return 0;
    }
    
    int ptrA = 0;
    int ptrB = 0;
    sumA = 0;
    sumB = 0;
    
    int ans = 0;
    while (ptrA <= n && ptrB <= m) {
        if (sumA <= sumB) {
            ptrA++;
            sumA += a[ptrA];
        } else {
            ptrB++;
            sumB += b[ptrB];
        }
        if (sumA == sumB) {
            sumA = sumB = 0;
            ans++;
        }
    }
    
    printf("%d\n", max(1, ans - 1));
    return 0;
}