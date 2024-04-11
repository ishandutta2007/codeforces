#include<bits/stdc++.h>
using namespace std;

#define maxn 200010
typedef long long ll;
int a[maxn];
int b[maxn];
int c[maxn];
int n,m,cnt,cnt1;
ll ans=-1,sum;

void getans(ll x)
{
    if (ans==-1)    ans=x;else
    if (ans!=x) {printf("-1\n");exit(0);}
}
void add(int x,int y)
{
    if (y==0)   return;
    if (b[x]==0)    cnt1++;
    b[x]+=y;
    if (b[x]==0)    cnt1--;
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)  scanf("%d",&a[i]);
    scanf("%d",&m);
    for (int i=1;i<=m;i++)
    {
        int x;
        scanf("%d",&x);
        c[x]++;
        if (c[x]==1)    cnt++;
    }
    {
        memcpy(b,c,sizeof(c));
        sum=0;
        cnt1=cnt;
        int dire=1;
        int pos=1;
        add(1,-1);
        for (int i=2;i<=m;i++)
        {
            pos+=dire;
            add(pos,-1);
            if (dire==1)    sum+=a[pos]-a[pos-1];else sum+=a[pos+1]-a[pos];
            if (pos==1) dire=1;
            if (pos==n) dire=-1;
        }
        int pos1=1;
        int dire1=1;
        for (int i=1;i<=2*n;i++)
        {
            if (cnt1==0)    getans(sum);
            sum-=abs(a[pos1+dire1]-a[pos1]);
            add(pos1,1);
            pos1+=dire1;
            if (pos1==1) dire1=1;
            if (pos1==n) dire1=-1;
            sum+=abs(a[pos+dire]-a[pos]);
            pos+=dire;
            add(pos,-1);
            if (pos==1) dire=1;
            if (pos==n) dire=-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}