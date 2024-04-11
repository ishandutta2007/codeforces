#include <bits/stdc++.h>
using namespace std;

int N;
char A[102];
bool D[102][8];
string S[102][8];

int main()
{
    scanf("%s", A+1); N = strlen(A+1);
    for (int i=1;i<=N;i++){
        if (A[i] == '0'){ puts("YES\n0"); return 0; }
    }
    D[0][0] = 1;
    for (int i=0;i<N;i++){
        for (int j=0;j<8;j++) if (D[i][j]){
            if (!D[i+1][j])
                D[i+1][j] = 1, S[i+1][j] = S[i][j];
            int k = (j*10 + A[i+1]-'0') & 7;
            D[i+1][k] = 1, S[i+1][k] = S[i][j] + string(1, A[i+1]);
        }
    }
    if (S[N][0].empty()){ puts("NO"); return 0; }
    puts("YES");
    bool sw = 0;
    for (char c: S[N][0]){
        if (c > '0') sw = 1;
        if (sw) printf("%c", c);
    }puts("");
}