#include<bits/stdc++.h>
using namespace std;
const int maxn = 2005;
inline int read(){
    int s=0;char ch=getchar();
    while(!isdigit(ch)) ch=getchar();
    while(isdigit(ch)) s=s*10+ch-48,ch=getchar();
    return s;
}
bool plot[maxn][maxn];
int r[maxn][maxn];
int n, m, k;
 
int check(int row, int col) {
    if (col >= 0 && col < m) return true;
    return false;
}
 
int main() {
    n=read(),m=read(),k=read();
    while(k--) {
        int x, y;
        x=read(),y=read();
        x --; y --;
        if (!plot[x][y]) {
            printf("%d %d\n", x + 1, y + 1);
            plot[x][y] = true;
            continue;
        }
        for (int d = 1; d <= 3; d ++) {
            int Max = min(n, x + d + 1);
            for (int row = max(0, x - d); row < Max; row ++) {
                int t = d - abs(x - row), col1 = y - t, col2 = y + t;
                if (check(row, col1)) r[x][y]=max(r[x][y], r[row][col1] - d);
                if (check(row, col2)) r[x][y]=max(r[x][y], r[row][col2] - d);
            }
        }
        for (int d = r[x][y] + 1; ; d ++) {
            int Max = min(n, x + d + 1);
            bool ok = false;
            for (int row = max(0, x - d); row < Max; row ++) {
                int t = d - abs(x - row), col1 = y - t, col2 = y + t;
                if (check(row, col1) && !plot[row][col1]) {
                    ok = true;
                    printf("%d %d\n", row + 1, col1 + 1);
                    plot[row][col1] = true;
                    break;
                }
                if (check(row, col2) && !plot[row][col2]) {
                    ok = true;
                    printf("%d %d\n", row + 1, col2 + 1);
                    plot[row][col2] = true;
                    break;
                }
            }
            if (ok) {
                r[x][y] = d - 1;
                break;
            }
        }
    }
    return 0;
}