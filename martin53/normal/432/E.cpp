#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n,m;
char output[nmax][nmax];
bool been[nmax][nmax];
int x_min,x_max,y_min,y_max;
void dfs(int x,int y,char c)
{
    if(x==0||x==n+1||y==0||y==m+1)return;
    if(been[x][y])return;
    if(output[x][y]!=c)return;
    been[x][y]=1;
    x_min=min(x_min,x);x_max=max(x_max,x);
    y_min=min(y_min,y);y_max=max(y_max,y);
    dfs(x+1,y,c);
    dfs(x-1,y,c);
    dfs(x,y-1,c);
    dfs(x,y+1,c);
}
bool inside(int a,int b,int c,int d,int x,int y)
{
    return a<=x&&x<=b&&c<=y&&y<=d;
}
bool test(int x,int y,char c)
{
    memset(been,0,sizeof(been));
    x_min=x;x_max=x;
    y_min=y;y_max=y;

    output[x][y]=c;

    dfs(x,y,c);

    //cout<<x<<" "<<y<<" "<<c<<" -> "<<x_min<<" "<<y_min<<" "<<x_max<<" "<<y_max<<endl;

    int d=max(x_max-x_min+1,y_max-y_min+1);
    x_max=x_min+d-1;
    y_max=y_min+d-1;

    if(x_max>n||y_max>m)return 0;

    //if(x_max-x_min!=y_max-y_min)return 0;

    for(int i=x_min-1;i<=x_max+1;i++)
        for(int j=y_min-1;j<=y_max+1;j++)
        {
        //cout<<i<<" "<<j<<endl;
        if(i==0||i==n+1||j==0||j==m+1)continue;
        if((i==x_min-1||i==x_max+1)&&(j==y_min-1||j==y_max+1))continue;
        if(inside(x_min,x_max,y_min,y_max,i,j)&&output[i][j]&&output[i][j]!=c){return 0;}
        if(inside(x_min,x_max,y_min,y_max,i,j)==0&&output[i][j]&&output[i][j]==c){return 0;}
        }

    for(int i=x_min;i<=x_max;i++)
        for(int j=y_min;j<=y_max;j++)
        output[i][j]=c;

    return 1;
}
int main()
{
cin>>n>>m;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(output[i][j]==0)
        for(char c='A';c<='Z';c++)
        if(test(i,j,c))break;

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=m;j++)cout<<output[i][j];
    cout<<endl;
}
return 0;
}