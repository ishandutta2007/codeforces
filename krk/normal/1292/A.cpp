#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n, q;
bool B[2][Maxn];
int forb;

void Change(int r, int c)
{
    if (B[r][c]) {
        for (int j = c - 1; j <= c + 1; j++)
            if (B[1 - r][j]) forb--;
        B[r][c] = false;
    } else {
        B[r][c] = true;
        for (int j = c - 1; j <= c + 1; j++)
            if (B[1 - r][j]) forb++;
    }
}

int main()
{
    scanf("%d %d", &n, &q);
    while (q--) {
        int r, c; scanf("%d %d", &r, &c);
        Change(r - 1, c);
        printf("%s\n", forb > 0? "No": "Yes");
    }
    return 0;
}