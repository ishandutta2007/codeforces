#include <stdio.h>

#define num(c) ((c)>'Z'?(c)-'a':(c)-'A'+26)
#define MOD 1000000007
typedef long long lld;

lld N;
int M,K,ans;
char buf[9];

struct MAT{
    int m[52][52];
    MAT operator * (const MAT &b)const{
        MAT ret={0,};
        int i,j,k;
        for (i=0;i<M;i++) for (j=0;j<M;j++){
            for (k=0;k<M;k++) ret.m[i][j] = (ret.m[i][j]+lld(m[i][k])*b.m[k][j]%MOD)%MOD;
        }
        return ret;
    }
} D[66],T;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
#endif
    int i,j,k;
    bool sw=0;
    scanf("%I64d%d%d",&N,&M,&K);
    for (i=0;i<M;i++) for (j=0;j<M;j++) D[0].m[i][j] = 1;
    for (i=0;i<M;i++) T.m[i][i] = 1;
    for (i=1;i<=K;i++){
        scanf("%s",buf);
        D[0].m[num(buf[1])][num(buf[0])] = 0;
    }
    for (i=1;i<62;i++) D[i] = D[i-1]*D[i-1];
    for (i=0;i<62;i++) if (((N-1)>>i)&1){
        if (!sw) T = D[i], sw = 1;
        else T = T*D[i];
    }
    for (i=0;i<M;i++){
        k = 0;
        for (j=0;j<M;j++) k = (k+T.m[i][j])%MOD;
        ans = (ans+k)%MOD;
    }
    printf("%d",ans);
}