#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42;
bool been[nmax][nmax];
int n;
int ax,ay;
int bx,by;
int cx,cy;
void dfs(int x,int y)
{
    if(x==0||y==0||x>n||y>n)return;
    if(x==ax||y==ay)return;
    if(x-y==ax-ay)return;
    if(x+y==ax+ay)return;
    if(x==cx&&y==cy)
    {
        printf("YES\n");
        exit(0);
    }
    if(been[x][y])return;
    been[x][y]=1;
    for(int p=-1;p<=1;p++)
        for(int q=-1;q<=1;q++)
        dfs(x+p,y+q);
}
int main()
{
scanf("%i",&n);
scanf("%i%i",&ax,&ay);
scanf("%i%i",&bx,&by);
scanf("%i%i",&cx,&cy);

dfs(bx,by);

printf("NO\n");
return 0;
}