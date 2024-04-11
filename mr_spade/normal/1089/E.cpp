#include<bits/stdc++.h>
using namespace std;
int n;
bool bo[10][10];
int main() {
    scanf("%d", &n);
    printf("a1 ");
    bo[1][1] = 1;
    bo[8][8] = 1;
    int x = 1, y = 1;
    while (--n) {
        if (n <= 5 && x != 8 && y != 8) {
            y = 8;
        } else {
            int nx = 0;
            for (int i = 8; i; --i) if (!bo[i][y]) {
                nx = i;
                break;
            }
            if (nx) x = nx; else ++y;
        }
        bo[x][y] = 1;
        printf("%c%d ", 'a' + x - 1, y);
    }
    puts("h8");
    return 0;
}