#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1010;
int n,ans,Q,op,x;
int a[MAXN][MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++) if(a[i][i]) ans^=1;
    scanf("%d",&Q);
    while(Q--)
    {
        scanf("%d",&op);
        if(op==3) putchar(ans+'0');
        else scanf("%d",&x),ans^=1;
    }
    puts("");
    return 0;
}