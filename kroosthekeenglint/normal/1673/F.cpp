#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[34][34],b[34][34];
int sum=0;
void find_pos(int code,int val,int n,int x,int y)
{
    if (n==1)
    {
        printf("%d %d\n",x+1,y+1);
        fflush(stdout);
        return;
    }
    if (code&val)
    {
        x+=n/2;
        code^=val;
        code^=(val>>2);
    }
    if (code&(val<<1))
    {
        y+=n/2;
        code^=(val<<1);
        code^=(val>>1);
    }
    find_pos(code,val>>2,n>>1,x,y);
}
void build_graph(int x,int y,int n,int val)
{
    if (n==1)
    {
        return;
    }
    int mid_x = x+n/2;
    int mid_y = y+n/2;
    int i;
    build_graph(x,y,n/2,val/4);
    build_graph(x,mid_y,n/2,val/4);
    build_graph(mid_x,y,n/2,val/4);
    build_graph(mid_x,mid_y,n/2,val/4);
    //mid_x-1 , mid_x, val
    for (i=y;i<y+n;i++)
    {
        a[mid_x-1][i]=val;
        sum+=val;
    }
    for (i=x;i<x+n;i++)
    {
        b[i][mid_y-1]=val*2;
        sum+=val*2;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,k;
    build_graph(0,0,32,256);
    scanf("%d%d",&n,&k);
    int i;
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<n-1;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    for (i=0;i<n-1;i++)
    {
        int j;
        for (j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    fflush(stdout);
    int current_xor=0;
    for (i=0;i<k;i++)
    {
        int x;
        scanf("%d",&x);
        current_xor^=x;
        find_pos(current_xor,256,32,0,0);
    }
    return 0;
}