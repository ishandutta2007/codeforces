#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Node
{
    int l,r,u,d,v;
}A[1010*1010];
int n,m,a[1010][1010],Q;
int main()
{
    scanf("%d%d%d",&n,&m,&Q);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%d",&a[i][j]);
    for(int i=0;i<=n+1;i++)
        for(int j=0;j<=m+1;j++)
        {
            if(j!=0) A[i*(m+2)+j].l=i*(m+2)+j-1;
            if(j!=m+1) A[i*(m+2)+j].r=i*(m+2)+j+1;
            if(i!=0) A[i*(m+2)+j].u=(i-1)*(m+2)+j;
            if(i!=n+1) A[i*(m+2)+j].d=(i+1)*(m+2)+j;
            if(i!=0&&j!=0&&i!=n+1&&j!=m+1) A[i*(m+2)+j].v=a[i][j];
        }
    while(Q--)
    {
        int a,b,c,d,h,w;
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&h,&w);
        int x=0,y=0;
        for(int i=1;i<=a;i++) x=A[x].d;
        for(int i=1;i<=b;i++) x=A[x].r;
        for(int i=1;i<=c;i++) y=A[y].d;
        for(int i=1;i<=d;i++) y=A[y].r;
        swap(A[A[x].u].d,A[A[y].u].d),swap(A[x].u,A[y].u);
        for(int i=1;i<w;i++) x=A[x].r,y=A[y].r,swap(A[A[x].u].d,A[A[y].u].d),swap(A[x].u,A[y].u);
        swap(A[A[x].r].l,A[A[y].r].l),swap(A[x].r,A[y].r);
        for(int i=1;i<h;i++) x=A[x].d,y=A[y].d,swap(A[A[x].r].l,A[A[y].r].l),swap(A[x].r,A[y].r);
        swap(A[A[x].d].u,A[A[y].d].u),swap(A[x].d,A[y].d);
        for(int i=1;i<w;i++) x=A[x].l,y=A[y].l,swap(A[A[x].d].u,A[A[y].d].u),swap(A[x].d,A[y].d);
        swap(A[A[x].l].r,A[A[y].l].r),swap(A[x].l,A[y].l);
        for(int i=1;i<h;i++) x=A[x].u,y=A[y].u,swap(A[A[x].l].r,A[A[y].l].r),swap(A[x].l,A[y].l);
    }
    int x=0;
    x=A[A[x].d].r;
    int head=x;
    for(int i=1;i<=n;i++)
    {
        int x=head;
        for(int j=1;j<m;j++)
            printf("%d ",A[x].v),x=A[x].r;
        printf("%d\n",A[x].v);
        head=A[head].d;
    }
    return 0;
}