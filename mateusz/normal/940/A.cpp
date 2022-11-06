#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int n, d;
int a[N];

int main() {
    
    scanf("%d %d", &n, &d);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a + 1, a + 1 + n);
    
    int ans = n;
    for (int i = 1; i <= n; i++) {
        int cnt = i - 1;
        for (int j = i + 1; j <= n; j++) {
            if (abs(a[i] - a[j]) > d) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    
    printf("%d\n", ans);
    
    return 0;
}