#include<bits/stdc++.h>
using namespace std;
const int nmax=2500+42;
int n,m;
int q;
pair<int/*y2*/,int/*which group*/> mem[nmax][nmax];
int ask(int x,int y)
{
    int ret=0;
    for(int j=1;j<=y;j++)
    {
        if(mem[x][j].first>=y)ret=mem[x][j].second;
    }
    return ret;
}
int main()
{
scanf("%i%i%i",&n,&m,&q);
int t,x1,y1,x2,y2;
int id=0;
for(int r=1;r<=q;r++)
{
    scanf("%i%i%i%i%i",&t,&x1,&y1,&x2,&y2);
    if(t==1)
    {
        id++;
        for(int i=x1;i<=x2;i++)
        mem[i][y1]={y2,id};
    }
    if(t==2)
    {
        for(int i=x1;i<=x2;i++)
        mem[i][y1]={0,0};
    }
    if(t==3)
    {
        if(ask(x1,y1)==ask(x2,y2))printf("Yes\n");
        else printf("No\n");
    }
}
return 0;
}