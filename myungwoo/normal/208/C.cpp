#include <stdio.h>

typedef long long lld;

int N,M; double ans;
lld D1[111],C1[111],D2[111],C2[111];
int w[111][111];
bool V[111];

int main()
{
    int i,j,k;
    lld cnt;
    for (scanf("%d%d",&N,&M);M--;){
        scanf("%d%d",&i,&j); w[i][j] = w[j][i] = 1;
    }
    for (i=0;i<=N;i++) D1[i] = D2[i] = 1e9;
    D1[1] = 0, D2[N] = 0; C1[1] = C2[N] = 1;
    for (i=1;i<=N;i++){
        for (j=k=0;j<=N;j++) if (!V[j] && D1[k] > D1[j]) k = j;
        V[k] = 1;
        for (j=1;j<=N;j++) if (w[k][j] && !V[j]){
            if (D1[j] == D1[k]+1)
                C1[j] += C1[k];
            else if (D1[j] > D1[k]+1)
                D1[j] = D1[k]+1, C1[j] = C1[k];
        }
    }
    for (i=1;i<=N;i++) V[i] = 0;
    for (i=1;i<=N;i++){
        for (j=k=0;j<=N;j++) if (!V[j] && D2[k] > D2[j]) k = j;
        V[k] = 1;
        for (j=1;j<=N;j++) if (w[k][j] && !V[j]){
            if (D2[j] == D2[k]+1)
                C2[j] += C2[k];
            else if (D2[j] > D2[k]+1)
                D2[j] = D2[k]+1, C2[j] = C2[k];
        }
    }
    for (i=1;i<=N;i++){
        cnt = 0;
        for (j=1;j<=N;j++) if (w[i][j]){
            if (D1[i]+D2[j]+1 == D1[N])
                cnt += C1[i]*C2[j];
            if (D2[i]+D1[j]+1 == D1[N])
                cnt += C2[i]*C1[j];
        }
        if (ans < double(cnt)/C1[N])
            ans = double(cnt)/C1[N];
    }
    printf("%.9lf",ans);
}