#include <stdio.h>
#include <string.h>

int N,nxt[100005][26];
char A[100005];

int main()
{
    int i,j,k;
    scanf("%s",A+1);
    N = strlen(A+1);
    for (i=N;i>0;i--){
        for (j=0;j<26;j++) nxt[i][j] = nxt[i+1][j];
        nxt[i][A[i]-'a'] = i;
    }
    for (k=0;;){
        for (i=26;i--;) if (nxt[k+1][i]){
            printf("%c",i+'a');
            k = nxt[k+1][i];
            break;
        }
        if (i < 0) break;
    }
}