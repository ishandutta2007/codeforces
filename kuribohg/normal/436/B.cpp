#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k,ans[2010];
char str[2010][2010];
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%s",str[i]+1);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(str[i][j]=='U')
            {
                if(i&1) ans[j]++;
            }
            else if(str[i][j]=='L')
            {
                if(j-i+1>=1) ans[j-i+1]++;
            }
            else if(str[i][j]=='R')
            {
                if(j+i-1<=m) ans[j+i-1]++;
            }
        }
    for(int i=1;i<=m;i++) printf("%d ",ans[i]);
    return 0;
}