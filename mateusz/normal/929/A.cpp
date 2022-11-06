#include <bits/stdc++.h>

using namespace std;

int main() {
    
    int n, k, x;
    scanf("%d %d", &n, &k);
    
    int myPos = -1;
    int last = -1;
    int ans = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (i > 1) {
            while (x - myPos > k) {
                if (last == myPos) {
                    printf("-1\n");
                    return 0;
                }
                ans++;
                myPos = last;
            }
        } else {
            myPos = x;
        }
        last = x;
    }
    
    printf("%d\n", ans);
    
    return 0;
}