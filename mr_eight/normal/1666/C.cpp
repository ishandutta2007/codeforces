#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
using namespace std;
struct node{int x,y;}a[3+5];
bool cmp(node A,node B)
{
    return A.x<B.x;
}
int main()
{
    int n=3,i,j;
    for (i=1;i<=n;i++)
        scanf("%d%d",&a[i].x,&a[i].y);
    sort(a+1,a+n+1,cmp);
    if (a[1].y>a[3].y)
        swap(a[1],a[3]);
    if (a[2].y>=a[3].y)
    {
        printf("%d\n",(a[1].y!=a[3].y)+(a[1].x!=a[3].x)+(a[2].y!=a[3].y));
        if (a[1].y!=a[3].y)
            printf("%d %d %d %d\n",a[1].x,a[1].y,a[1].x,a[3].y);
        if (a[1].x!=a[3].x)
            printf("%d %d %d %d\n",a[1].x,a[3].y,a[3].x,a[3].y);
        if (a[2].y!=a[3].y)
            printf("%d %d %d %d\n",a[2].x,a[3].y,a[2].x,a[2].y);
        return 0;
    }
    if (a[2].y<=a[1].y)
    {
        printf("%d\n",(a[1].y!=a[3].y)+(a[1].x!=a[3].x)+(a[2].y!=a[1].y));
        if (a[1].y!=a[3].y)
            printf("%d %d %d %d\n",a[3].x,a[1].y,a[3].x,a[3].y);
        if (a[1].x!=a[3].x)
            printf("%d %d %d %d\n",a[1].x,a[1].y,a[3].x,a[1].y);
        if (a[2].y!=a[1].y)
            printf("%d %d %d %d\n",a[2].x,a[2].y,a[2].x,a[1].y);
        return 0;
    }
    printf("%d\n",(a[1].y!=a[2].y)+(a[1].x!=a[3].x)+(a[2].y!=a[3].y));
    if (a[1].y!=a[2].y)
        printf("%d %d %d %d\n",a[1].x,a[1].y,a[1].x,a[2].y);
    if (a[2].y!=a[3].y)
        printf("%d %d %d %d\n",a[3].x,a[2].y,a[3].x,a[3].y);
    if (a[1].x!=a[3].x)
        printf("%d %d %d %d\n",a[1].x,a[2].y,a[3].x,a[2].y);
}