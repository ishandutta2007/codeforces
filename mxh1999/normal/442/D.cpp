#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

#define maxn 1000010
#define PII pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
int ojc[maxn];
int res[maxn];
int a[maxn],b[maxn];
int n;

int calc(int n)
{
    for (int i=1;i<=n;i++)  a[i]=b[i]=0;
    for (int i=n;i>1;i--)
    {
        int x=max(a[i],b[i]+1),o=ojc[i];
        if (x>a[o])
        {
            b[o]=a[o];
            a[o]=x;
        }   else    b[o]=max(b[o],x);
    }
    return a[1];
}
int main()
{
    scanf("%d",&n);
    n++;
    for (int i=2;i<=n;i++)  scanf("%d",&ojc[i]);
    res[1]=res[2]=1;
    res[n]=calc(n);
    vector<PII> W;
    W.pb(mp(2,n));
    for (int i=0;i<W.size();i++)
    {
        int l=W[i].fi,r=W[i].se;
        if (res[l]==res[r])
        {
            for (int j=l;j<=r;j++)  res[j]=res[l];
        }   else
        if (r-l>1)
        {
            int mid=(l+r)/2;
            res[mid]=calc(mid);
            W.pb(mp(l,mid));
            W.pb(mp(mid,r));
        }
    }
    for (int i=2;i<=n;i++)  printf("%d\n",res[i]);
    return 0;
}