#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define a(x,y) ans[(x)+(n)-(1)][(y)+(n)-(1)]
using namespace std;
int n;
char str[110][110],ans[110][110],res[110][110];
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",str[i]);
    a(0,0)='o';
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(str[i][j]=='o')
            {
                for(int x=0;x<n;x++)
                    for(int y=0;y<n;y++)
                        if(str[x][y]=='.')
                            a(x-i,y-j)='.';
            }
    for(int x=-n+1;x<n;x++)
        for(int y=-n+1;y<n;y++)
            if(!a(x,y)) a(x,y)='x';
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(str[i][j]=='o') res[i][j]='o';
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(str[i][j]=='o')
            {
                for(int x=-n+1;x<n;x++)
                    for(int y=-n+1;y<n;y++)
                        if(i+x<n&&i+x>=0&&j+y<n&&j+y>=0&&a(x,y)=='x'&&!res[i+x][j+y])
                            res[i+x][j+y]='x';
            }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(!res[i][j]) res[i][j]='.';
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(str[i][j]!=res[i][j]) {puts("NO");return 0;}
    puts("YES");
    for(int i=0;i<(n<<1)-1;i++) puts(ans[i]);
    return 0;
}