#include <bits/stdc++.h>
using namespace std;

const int Maxd = 4;
const int dy[Maxd] = {-1, 0, 1, 0};
const int dx[Maxd] = {0, -1, 0, 1};

int n;

int main()
{
    scanf("%d", &n);
    printf("0 0\n"); n--;
    for (int i = 0; i < n; i++) {
        int r = (i / 4 + 1) * dy[i % 4];
        int c = (i / 4 + 1) * dx[i % 4];
        printf("%d %d\n", r, c);
    }
    return 0;
}