#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
typedef long long LL;
const int MOD=1000000007;
const int MAXN=210;
int n,k;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int f[210][22][23],ans;
void DFS(int x,int fa)
{
    int w[22][23];
    for(int p=0;p<=k+1;p++)
        for(int q=0;q<=k+2;q++)
            w[p][q]=0;
    f[x][0][k+2]=1,f[x][k+1][0]=1;
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            DFS(to[i],x);
            for(int pl=0;pl<=k+1;pl++)
                for(int pr=0;pr<=k+1;pr++)
                    for(int ql=0;ql<=k+2;ql++)
                        for(int qr=0;qr<=k+2;qr++)
                        {
                            int np=k+1,nq=-1;
                            bool l_ok=(ql==k+2||pr+ql<=k-1);
                            bool r_ok=(qr==k+2||pl+qr<=k-1);
                            if(l_ok&&r_ok) nq=k+2;
                            else if(l_ok) nq=min(k+1,qr+1);
                            else if(r_ok) nq=min(k+1,ql);
                            else nq=min(k+1,max(ql,qr+1));
                            np=min(pl,pr+1);
                            w[np][nq]=(w[np][nq]+(LL)f[x][pl][ql]*f[to[i]][pr][qr])%MOD;
                        }
            for(int p=0;p<=k+1;p++)
                for(int q=0;q<=k+2;q++)
                    f[x][p][q]=w[p][q],w[p][q]=0;
        }
}
int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    DFS(1,-1);
    for(int i=0;i<=k;i++)
        ans=(ans+f[1][i][k+2])%MOD;
    printf("%d\n",ans);
    return 0;
}