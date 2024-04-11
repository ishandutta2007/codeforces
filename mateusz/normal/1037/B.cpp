#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int n, median;
int tab[N];

int main() {
    
    scanf("%d %d", &n, &median);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &tab[i]);
    }
    
    sort(tab + 1, tab + 1 + n);
    
    int mid = n / 2 + 1;
    long long ans = 0;
    if (tab[mid] < median) {
        for (int i = mid; i <= n; i++) {
            ans += max(0, median - tab[i]);
        }
    } else {
        for (int i = mid; i >= 1; i--) {
            ans += max(0, tab[i] - median);
        }
    }
    
    printf("%lld\n", ans);
    
    return 0;
}