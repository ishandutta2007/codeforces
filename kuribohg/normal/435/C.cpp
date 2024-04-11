#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cstdlib>
#include<ctime>
using namespace std;
int n,a[1010],m,num,x,y,u,xt;
char p[1010][1010];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
    {
        if(i&1) num+=a[i],m=min(m,num),u=max(u,num);
        else num-=a[i],m=min(m,num),u=max(u,num);
    }
    m=-m,u+=m;
    x=0,y=m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=a[i];j++)
        {
            if(j!=1){
            if(i&1) y++;
            else y--;}
            x++;
            if(i&1) p[y][x]='/';
            else p[y][x]='\\';
        }
    }
    for(int i=1;i<=n;i++) xt+=a[i];
    for(int i=u-1;i>=0;i--)
    {
        for(int j=1;j<=xt;j++)
            putchar(p[i][j]!=0?p[i][j]:' ');
        puts("");
    }
    return 0;
}