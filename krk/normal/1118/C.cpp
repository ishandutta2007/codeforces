#include <bits/stdc++.h>
using namespace std;

const int Maxn = 21;
const int Maxm = 1005;

int n;
int freq[Maxm];
int B[Maxn][Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        int a; scanf("%d", &a);
        freq[a]++;
    }
    int pnt = 0;
    for (int i = 0; i < n - 1 - i; i++)
        for (int j = 0; j < n - 1 - j; j++) {
            while (pnt < Maxm && freq[pnt] < 4) pnt++;
            if (pnt < Maxm) {
                freq[pnt] -= 4;
                B[i][j] = B[i][n - 1 - j] = B[n - 1 - i][j] = B[n - 1 - i][n - 1 - j] = pnt;
            } else { printf("NO\n"); return 0; }
        }
    pnt = 0;
    if (n % 2 == 1) {
        int mid = n / 2;
        for (int i = 0; i < n - 1 - i; i++) {
            while (pnt < Maxm && freq[pnt] < 2) pnt++;
            if (pnt < Maxm) {
                freq[pnt] -= 2;
                B[mid][i] = B[mid][n - 1 - i] = pnt;
            } else { printf("NO\n"); return 0; }
            while (pnt < Maxm && freq[pnt] < 2) pnt++;
            if (pnt < Maxm) {
                freq[pnt] -= 2;
                B[i][mid] = B[n - 1 - i][mid] = pnt;
            } else { printf("NO\n"); return 0; }
        }
        pnt = 0;
        while (pnt < Maxm && freq[pnt] < 1) pnt++;
        if (pnt < Maxm) {
            freq[pnt]--;
            B[mid][mid] = pnt;
        } else { printf("NO\n"); return 0; }
    }
    printf("YES\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", B[i][j], j + 1 < n? ' ': '\n');
    return 0;
}