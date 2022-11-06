#include <bits/stdc++.h>

using namespace std;

char seq[100005];

int main() {
    
    int n;
    scanf("%d", &n);
    
    scanf("%s", &seq[1]);
    
    int ans = 0;
    int x = 0, y = 0, side = 0;
    for (int i = 1; i <= n; i++) {
        if (seq[i] == 'R') x++;
        else y++;
        int newSide = (x < y ? 1 : x > y ? -1 : side);
        if (newSide == -side) {
            ans++;
        }
        side = newSide;
    }
    
    printf("%d\n", ans);
    
    return 0;
}