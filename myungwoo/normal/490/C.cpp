#include <stdio.h>
#include <string.h>

#define MAXN 1000006
typedef long long lld;

int N, A, B, V[MAXN];
char S[MAXN];
bool P[MAXN];

int main()
{
    int i;
    scanf("%s%d%d", S+1, &A, &B);
    N = strlen(S+1);
    int v = 0;
    V[N] = 1;
    for (i=N;--i;) V[i] = (lld)V[i+1]*10%B;
    for (i=1;i<=N;i++){
        v = ((lld)v*10 + S[i]-'0')%A;
        if (!v) P[i] = 1;
    }
    v = 0;
    for (i=N;i>1;i--){
        v = (v+((lld)V[i]*(S[i]-'0'))%B)%B;
        if (!v && S[i]-'0' && P[i-1]){
            puts("YES");
            for (int j=1;j<i;j++) printf("%c", S[j]); puts("");
            for (int j=i;j<=N;j++) printf("%c", S[j]); puts("");
            return 0;
        }
    }
    puts("NO");
}