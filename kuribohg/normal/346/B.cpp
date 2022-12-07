#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
const int INF=1000000000;
char S[110],T[110],str[110];
int n,m,K,f[110][110][110],next[110];
int pre_i[110][110][110],pre_j[110][110][110],pre_k[110][110][110];
void initKMP()
{
    int j=0,len=strlen(str+1);
    for(int i=2;i<=len;i++)
    {
        while(j&&str[j+1]!=str[i]) j=next[j];
        if(str[j+1]==str[i]) j++;
        next[i]=j;
    }
}
int ans=-INF,sub;
char A[110],tot;
int main()
{
    scanf("%s%s%s",S+1,T+1,str+1);
    n=strlen(S+1),m=strlen(T+1),K=strlen(str+1);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            for(int k=0;k<=K;k++)
                f[i][j][k]=-INF;
    for(int i=0;i<=n;i++) f[i][0][0]=0;
    for(int i=0;i<=m;i++) f[0][i][0]=0;
    initKMP();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            for(int k=0;k<K;k++)
            {
                if(S[i]==T[j])
                {
                    if(S[i]==str[k+1])
                    {
                        if(f[i-1][j-1][k]+1>f[i][j][k+1])
                            f[i][j][k+1]=f[i-1][j-1][k]+1,pre_i[i][j][k+1]=i-1,pre_j[i][j][k+1]=j-1,pre_k[i][j][k+1]=k;
                    }
                    else
                    {
                        int nk=k;
                        while(nk&&str[nk+1]!=S[i]) nk=next[nk];
                        if(str[nk+1]==S[i]) nk++;
                        if(f[i-1][j-1][k]+1>f[i][j][nk])
                            f[i][j][nk]=f[i-1][j-1][k]+1,pre_i[i][j][nk]=i-1,pre_j[i][j][nk]=j-1,pre_k[i][j][nk]=k;
                    }
                }
                if(f[i-1][j][k]>f[i][j][k]) f[i][j][k]=f[i-1][j][k],pre_i[i][j][k]=i-1,pre_j[i][j][k]=j,pre_k[i][j][k]=k;
                if(f[i][j-1][k]>f[i][j][k]) f[i][j][k]=f[i][j-1][k],pre_i[i][j][k]=i,pre_j[i][j][k]=j-1,pre_k[i][j][k]=k;
            }
    for(int k=0;k<K;k++)
        if(f[n][m][k]>ans) ans=f[n][m][k],sub=k;
    if(ans<=0) {puts("0");return 0;}
    int nowi=n,nowj=m,nowk=sub;
    while(f[nowi][nowj][nowk])
    {
        if(pre_i[nowi][nowj][nowk]==nowi-1&&pre_j[nowi][nowj][nowk]==nowj-1) A[++tot]=S[nowi];
        int ni,nj,nk;
        ni=pre_i[nowi][nowj][nowk];
        nj=pre_j[nowi][nowj][nowk];
        nk=pre_k[nowi][nowj][nowk];
        nowi=ni,nowj=nj,nowk=nk;
    }
    reverse(A+1,A+tot+1);
    puts(A+1);
    return 0;
}