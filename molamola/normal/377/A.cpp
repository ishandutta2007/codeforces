#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
using namespace std;


int xx[4]={-1,0,0,1}, yy[4]={0,-1,1,0};
char ch[505][505];
bool check[505][505];
int n,m,k,sx=0,sy=0;

int f(int x,int y)
{
    int c=0;
    for(int i=0;i<4;i++){
        if(ch[x+xx[i]][y+yy[i]]=='.')c++;
    }
    return c;
}

void dfs(int x,int y)
{
    if(k==0)return;
    check[x][y]=true;
    int i;
    for(i=0;i<4;i++){
        if(ch[x+xx[i]][y+yy[i]]!='.'||check[x+xx[i]][y+yy[i]])continue;
        dfs(x+xx[i],y+yy[i]);
    }
    if(k>0){
        k--;
        ch[x][y]='X';
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",ch[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(f(i,j)==1){
                sx=i; sy=j;
            }
        }
    }
    if(sx==0&&sy==0);
    else dfs(sx,sy);
    for(int i=1;i<=n;i++)printf("%s\n",ch[i]);
}