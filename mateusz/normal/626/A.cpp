#include <bits/stdc++.h>

using namespace std;
int ile[2005][2005];
int n;
char moves[2005];
int main() {
    scanf("%d", &n);
    scanf("%s", &moves[1]);
    
    
    int x = 1000;
    int y = 1000;
    ile[x][y] = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (moves[i] == 'U')
            x++;
        else if (moves[i] == 'D') {
            x--;
        } else if (moves[i] == 'L') {
            y++;
        } else y--;
        ans += ile[x][y];
        ile[x][y]++;
    }
    printf("%d\n", ans);
    return 0;
}