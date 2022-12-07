#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
const int maxn=800;
const int maxm=200005;

LL a[maxn],b[maxn];
priority_queue< LL , vector<LL>, greater<LL> > q;
LL ord[maxm];
LL mm,mi,tot;
int i,j,k,m,n;

int find(LL t)
{
    int ans=0;
    LL sum=0;
    while(!q.empty())q.pop();
    for(int i=1;i<=n;i++)
    {
        q.push(a[i]);
        sum+=a[i];
        while(sum+t<0)
        {
            LL temp=q.top();q.pop();
            if(temp>0)break;
            sum-=temp;
            ans++;
        }
    }
    return ans;
}

int main()
{
    scan2(n,m);
    mm=mi=tot=0;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        tot+=a[i];
        mi=min(tot,mi);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%lld",&ord[i]);
        mm=max(mm,ord[i]);
    }
    if(mi<0)mm=min(mm,-mi);
    else
    {
        for(i=1;i<=m;i++)printf("0\n");
        return 0;
    }
    for(i=0;i<=n;i++)
    {
        LL l=0,r;
        if(i==0)r=mm+1;else r=b[i-1]+1;
        while(r-l>1)
        {
            LL mid=(l+r)>>1;
            if(find(mid)>i)l=mid;else r=mid;
        }
        if(find(l)>i)l++;
        b[i]=l;
    }
    //for(i=0;i<=n;i++)printf("%d %lld\n",i,b[i]);
    for(int i=1;i<=m;i++)
    {
        LL x=ord[i];
        int l=0,r=n;
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(b[mid]>x)l=mid;else r=mid;
        }
        if(b[l]>x)l++;
        printf("%d\n",l);
    }
    return 0;
}