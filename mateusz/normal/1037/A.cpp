#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n;
    scanf("%d", &n);
    
    int ans = 0;
    while (n >= 1) {
        ans++;
        n /= 2;
    }
    
    printf("%d\n", ans);
    
    return 0;
}