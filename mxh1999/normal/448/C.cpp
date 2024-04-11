#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

#define maxn 5010
int n;
int a[maxn];
int b[maxn];

int search(int l,int r)
{
    int minx=b[l];
    int ans=0;
    for (int i=l;i<=r;i++)
        if (b[i]<minx)  minx=b[i];
    for (int i=l;i<=r;i++)  b[i]-=minx;
    ans=minx;
    int ll=l;
    for (int i=l;i<=r;i++)
    {
        if (b[i]!=0 && b[ll]==0)    ll=i;
        if (b[i]==0 && b[ll]!=0)    {ans+=search(ll,i-1);ll=i;}
    }
    if (b[ll]!=0)   ans+=search(ll,r);
    if (ans>(r-l+1))    ans=r-l+1;
    return ans;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    cout<<search(1,n)<<endl;
    return 0;
}