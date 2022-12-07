#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#include<cstdlib>
using namespace std;
int n,a[110],ans[110],sub;
int p[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
int f[110][1<<16],s[110][1<<16],fact[60],r[60];
void init_fact(int n)
{
    int nn=n;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
        {
            n/=i;
            while(n%i==0) n/=i;
            fact[nn]|=(1<<r[i]);
        }
    if(n>1) fact[nn]|=(1<<r[n]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=0;i<16;i++) r[p[i]]=i;
    for(int i=1;i<59;i++) init_fact(i);
    for(int i=0;i<=n;i++)
        for(int j=0;j<(1<<16);j++)
            f[i][j]=-1;
    f[0][0]=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<16);j++)
            if(f[i][j]!=-1)
            {
                for(int k=1;k<59;k++)
                    if((j|fact[k])==(j+fact[k]))
                    {
                        if(f[i+1][j|fact[k]]==-1||f[i+1][j|fact[k]]>f[i][j]+abs(k-a[i+1]))
                            f[i+1][j|fact[k]]=f[i][j]+abs(k-a[i+1]),s[i+1][j|fact[k]]=k;
                    }
            }
    for(int i=0;i<(1<<16);i++)
        if(f[n][i]!=-1&&f[n][sub]>f[n][i]) sub=i;
    for(int i=n;i>=1;i--)
    {
        ans[i]=s[i][sub];
        sub^=fact[s[i][sub]];
    }
    for(int i=1;i<n;i++) printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}