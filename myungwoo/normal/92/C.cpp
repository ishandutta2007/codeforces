#include <stdio.h>
#include <string.h>

#define MAXN 1000006
#define MAXM 10004

int N,M,ans;
int nxt[MAXM][26];
char A[MAXN],P[MAXM];

int main()
{
    int i,j,k;
    scanf("%s%s",P+1,A+1);
    M = strlen(P+1), N = strlen(A+1);
    for (i=M;i>0;i--){
        for (j=0;j<26;j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][P[i]-'a'] = i;
    }
    k = 0;
    for (i=1;i<=N&&ans<N;i++){
        if (!nxt[1][A[i]-'a']){ puts("-1"); return 0; }
        do{
            if (!k) ans++;
            k = nxt[k+1][A[i]-'a'];
        } while (!k);
    }
    printf("%d",ans);
}