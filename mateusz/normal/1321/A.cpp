#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int n;
int a[N], b[N];

int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    
    int firstWin = 0, secondWin = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &b[i]);
        if (a[i] && !b[i]) firstWin++;
        if (!a[i] && b[i]) secondWin++;
    }
    
    if (firstWin == 0) {
        printf("-1\n");
    } else {
        printf("%d\n", (firstWin + secondWin) / (firstWin));
    }
    
    return 0;
}