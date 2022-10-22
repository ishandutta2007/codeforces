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
int a[100005];
int fa[100005];
vector<int> v[100005];
int n;
int findroot(int x)
{
    int root;
    for (root=x;fa[root]!=-1;root=fa[root]) ;
    int temp;
    for (;fa[x]!=-1;)
    {
        temp = fa[x];
        fa[x]= root;
        x=temp;
    }
    return root;
}
void u(int x,int y,int z)
{
    x = findroot(x);
    y = findroot(y);
    if (x==y)
    {
        return;
    }
    if (v[x].size()>v[y].size())
    {
        swap(x,y);
    }
    int i;
    for (i=0;i<v[x].size();i++)
    {
        int t=v[x][i];
        if ((t!=0)&&(findroot(t-1)==y))
        {
            a[t] = z;
        }
        if ((t!=n-1)&&(findroot(t+1)==y))
        {
            a[t+1] = z;
        }
        v[y].push_back(t);
    }
    fa[x]=y;
    v[x].clear();
}
int ans[1<<19]; 
void build_tree(int num,int l,int r)
{
    if (l==r-1)
    {
        ans[num] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build_tree(num*2+1,l,mid);
    build_tree(num*2+2,mid,r);
    ans[num]=max(ans[num*2+1],ans[num*2+2]);
} 
int query(int num,int l,int r,int l0,int r0)
{
    if ((l0<=l)&&(r<=r0))
    {
        return ans[num];
    }
    int mid=(l+r)/2;
    int max_ans = 0;
    if (l0<mid)
    {
        max_ans=max(max_ans,query(num*2+1,l,mid,l0,r0));
    }
    if (mid<r0)
    {
        max_ans=max(max_ans,query(num*2+2,mid,r,l0,r0)); 
    }
    return max_ans;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int m,q;
        scanf("%d%d%d",&n,&m,&q);
        int i;
        for (i=0;i<n;i++)
        {
            fa[i]=-1;
            v[i].clear();
            v[i].push_back(i);
        }
        for (i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            x--;
            y--;
            u(x,y,i+1);
        }
        build_tree(0,1,n);
        for (i=0;i<q;i++)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            if (l==r)
            {
                printf("0 ");
            }
            else
            {
                printf("%d ",query(0,1,n,l,r));
            }
        }
        printf("\n");
    }
    return 0;
}