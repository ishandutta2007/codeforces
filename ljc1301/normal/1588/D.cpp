#include <bits/stdc++.h>
using namespace std;
const int maxn=12;
const int maxlen=200;
const int maxc=52;
const int inf=0x7fffffff;
char s[maxn][maxlen],sta[maxlen];
int pos[maxn][maxc][2],len[maxn];
int f[maxlen][(1<<(maxn-1))|1],pre[maxlen][(1<<(maxn-1))|1][2];
int g[(1<<(maxn-1))|1],preg[(1<<(maxn-1))|1][2];
int main()
{
    int T,n,i,j,k,l,t,ans,ansi,ansj;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            len[i]=strlen(s[i]);
            for(j=0;j<maxc;j++) pos[i][j][0]=pos[i][j][1]=inf;
            for(j=0;j<len[i];j++)
            {
                s[i][j]=(s[i][j]>='a')?s[i][j]-'a':(s[i][j]-'A'+26);
                if(pos[i][s[i][j]][0]==inf) pos[i][s[i][j]][0]=j;
                else pos[i][s[i][j]][1]=j;
            }
        }
        ans=0,ansi=ansj=-1;
        for(i=0;i<len[0];i++)
            for(j=0;j<(1<<(n-1));j++)
            {
                // if(!i) f[i][j]=0,pre[i][j][0]=pre[i][j][1]=-1;
                // else f[i][j]=f[i-1][j],pre[i][j][0]=pre[i-1][j][0],pre[i][j][1]=pre[i-1][j][1];
                // t=0;
                // for(k=1;k<n;k++)
                //     if(pos[k][s[0][i]][0]>pos[k][s[0][i]][0])
                pre[i][j][0]=pre[i][j][1]=-1;
                for(k=1;k<n;k++)
                    if(pos[k][s[0][i]][(j>>(k-1))&1]==inf)
                        break;
                if(k<n) { f[i][j]=0; continue; }
                f[i][j]=1;
                for(k=0;k<i;k++)
                {
                    t=0;
                    for(l=1;l<n;l++)
                        if(pos[l][s[0][k]][1]<pos[l][s[0][i]][(j>>(l-1))&1]) t|=1<<(l-1);
                        else if(pos[l][s[0][k]][0]>=pos[l][s[0][i]][(j>>(l-1))&1]) break;
                    if(l<n) continue;
                    if(f[k][t]+1>f[i][j])
                        f[i][j]=f[k][t]+1,pre[i][j][0]=k,pre[i][j][1]=t;
                }
                if(f[i][j]>ans) ans=f[i][j],ansi=i,ansj=j;
            }
        printf("%d\n",ans),i=ansi,j=ansj;
        // printf("%d %d\n",ansi,ansj);
        for(k=ans-1,sta[ans]='\0';k>=0;k--)
        {
            sta[k]=(s[0][i]<26)?s[0][i]+'a':(s[0][i]-26+'A');
            t=pre[i][j][0],j=pre[i][j][1],i=t;
        }
        printf("%s\n",sta);
    }
    return 0;
}