#include <bits/stdc++.h>
using namespace std;

int N, M;
char A[101][102]; int B[101][101];

int main()
{
    scanf("%d%d", &N, &M);
    for (int i=1;i<=N;i++) scanf("%s", A[i]+1);
    int ans = 0;
    for (int i=N;i;i--){
        for (int j=M;j;j--){
            int v = A[i][j] == 'W' ? 1 : -1;
            if (B[i][j] == v) continue;
            ans++;
            int a = v-B[i][j];
            for (int y=1;y<=i;y++) for (int x=1;x<=j;x++)
                B[y][x] += a; 
        }
    }
    printf("%d\n", ans);
}