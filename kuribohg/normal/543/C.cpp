#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int INF=1000000000;
int n,m,a[30][30];
int S[30][30],c[30][30],d[2000010];
char str[30][30];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<m;i++)
        for(int j=0;j<26;j++)
        {
            int x=0,s=0,state=0;
            for(int k=0;k<n;k++)
                if(str[k][i]-'a'==j) state|=(1<<k),s+=a[k][i],x=max(x,a[k][i]);
            for(int k=0;k<n;k++)
                if(str[k][i]-'a'==j) S[i][k]=state,c[i][k]=s-x;
        }
    for(int i=1;i<(1<<n);i++) d[i]=INF;
    for(int i=0;i<(1<<n)-1;i++)
    {
        int lowbit=-1;
        for(int j=0;j<n;j++) if(!(i&(1<<j))) {lowbit=j;break;}
        for(int j=0;j<m;j++)
            d[i|(1<<lowbit)]=min(d[i|(1<<lowbit)],d[i]+a[lowbit][j]);
        for(int j=0;j<m;j++)
            d[i|S[j][lowbit]]=min(d[i|S[j][lowbit]],d[i]+c[j][lowbit]);
    }
    printf("%d\n",d[(1<<n)-1]);
    return 0;
}