#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,dis[410][410];
char a[110],b[110];
bool ok=true;
inline int hash(int x,int y)
{
    return x*m+y+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s%s",a,b);
    for(int i=0;i<n;i++)
    {
        if(a[i]=='<')
        {
            for(int j=0;j<m-1;j++)
            {
                dis[hash(i,j+1)][hash(i,j)]=1;
                //cout<<hash(i,j+1)<<" "<<hash(i,j)<<endl;
            }
        }
        else if(a[i]=='>')
        {
            for(int j=0;j<m-1;j++)
            {
                dis[hash(i,j)][hash(i,j+1)]=1;
                //cout<<hash(i,j)<<" "<<hash(i,j+1)<<endl;
            }
        }
    }
    for(int i=0;i<m;i++)
    {
        if(b[i]=='^')
        {
            for(int j=0;j<n-1;j++)
            {
                dis[hash(j+1,i)][hash(j,i)]=1;
                //cout<<hash(j+1,i)<<" "<<hash(j,i)<<endl;
            }
        }
        else if(b[i]=='v')
        {
            for(int j=0;j<n-1;j++)
            {
                dis[hash(j,i)][hash(j+1,i)]=1;
                //cout<<hash(j,i)<<" "<<hash(j+1,i)<<endl;
            }
        }
    }
    for(int i=1;i<=n*m;i++) dis[i][i]=1;
    for(int k=1;k<=n*m;k++)
        for(int i=1;i<=n*m;i++)
            for(int j=1;j<=n*m;j++)
                dis[i][j]|=(dis[i][k]&dis[k][j]);
    for(int i=1;i<=n*m;i++)
        for(int j=1;j<=n*m;j++)
            if(!dis[i][j]) ok=false;
    if(ok) puts("YES");
    else puts("NO");
    return 0;
}