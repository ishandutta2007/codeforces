#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,m,k,a[100010],BIT[100010],l,r=2e9,mid;
void change(int x,int k)
{
    for(int i=x;i<=n;i+=(i&(-i))) BIT[i]+=k;
}
int query(int x)
{
    int con=0;
    for(int i=x;i>0;i^=(i&(-i))) con+=BIT[i];
    return con;
}
bool check()
{
    long long con=0;
    for(int i=1;i<=n;i++) BIT[i]=a[i]-a[i^(i&(-i))];
    for(int i=1;i<=n;i++)
    {
        int p=query(i);
        if(p<mid)
        {
            con+=mid-p;
            change(i,mid-p);
            if(i+k<=n) change(i+k,p-mid);
        }
    }
    return con<=m;
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),r=min(r,a[i]);
    r+=m;
    while(l<r)
    {
        mid=(l+r+1)>>1;
        if(check()) l=mid;
        else r=mid-1;
    }
    printf("%d\n",l);
    return 0;
}