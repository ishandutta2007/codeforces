#include <bits/stdc++.h>

using namespace std;
const int N = 55;
char look[4] = {'f', 'a', 'c', 'e'};
char board[N][N];
int n, m;
int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        scanf("%s", &board[i][1]);
    }
    int ans = 0;
    for(int i = 1; i <= n - 1; i++) {
        for(int j = 1; j <= m - 1; j++) {
            int cnt = 1;
            for(int k = 0; k < 4; k++) {
                bool found = false;
                for(int l = 0; l < 2; l++) {
                    for(int r = 0; r < 2; r++) {
                        if(board[i + l][j + r] == look[k]) {
                            found = true;
                            break;
                        }
                    }
                    if(found) break;
                }
                if(!found)
                    cnt = 0;
            }
            ans += cnt;
        }
    }
    printf("%d\n", ans);
    return 0;
}