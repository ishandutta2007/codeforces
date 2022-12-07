#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,c[11000],ans;
char str[110][110];
inline int Hash(int i,int j)
{
    if(i<0||j<0) return 0;
    return i*m+j+1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            int tar=0;
            if(str[i][j]=='B') tar=1;
            else tar=-1;
            c[Hash(i,j)]+=tar;
            c[Hash(i-1,j)]-=tar;
            c[Hash(i,j-1)]-=tar;
            c[Hash(i-1,j-1)]+=tar;
        }
    for(int i=1;i<=n*m;i++)
        if(c[i]) ans++;
    printf("%d\n",ans);
    return 0;
}