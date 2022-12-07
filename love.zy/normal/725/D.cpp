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
 
LL n1,n2;

int i,j,k,l,m,n,ans;

struct team
{
    LL t,w;
}a[300005];

struct pp
{
    LL num;
    int pos;
    pp(LL num=0,int pos=0):num(num),pos(pos){}
    bool operator < (const struct pp p)const
    {return num<p.num;}
};

struct tree
{
    int ls,rs,ll,rr;
    pp num;
}tr[1000005];

bool cmp(team x,team y)
{
    return x.t>y.t;
}

int find(LL t)
{
    //if(a[1].t<=t)return 1;
    //if(a[n].t>t)return n+1;
    int l=0,r=n;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        if(a[mid].t>t)l=mid;else r=mid;
    }
    if(a[r].t<=t)r--;
    return r+1;
}

void mt(int l,int r)
{
    if(l==r)
    {
        tr[k].ls=tr[k].rs=0;
        tr[k].ll=tr[k].rr=r;
        tr[k].num=pp(a[l].w-a[l].t+1,l);
        return;
    }
    int mid=(l+r)>>1;
    int temp=k;
    tr[temp].ll=l;tr[temp].rr=r;
    k++;tr[temp].ls=k;mt(l,mid);
    k++;tr[temp].rs=k;mt(mid+1,r);
    tr[temp].num=min(tr[tr[temp].ls].num,tr[tr[temp].rs].num);
}

pp search(int l,int r,int now)
{
    if(tr[now].ll==l && tr[now].rr==r)return tr[now].num;
    int mid=(tr[now].ll+tr[now].rr)>>1;
    if(mid<l)return search(l,r,tr[now].rs);
    if(mid>=r)return search(l,r,tr[now].ls);
    return min(search(l,mid,tr[now].ls),search(mid+1,r,tr[now].rs));
}

void change(int posi,int now)
{
    if(tr[now].ll==posi && tr[now].rr==posi)
    {
        tr[now].num.num=2e18;
        return;
    }
    int mid=(tr[now].ll+tr[now].rr)>>1;
    if(posi<=mid)change(posi,tr[now].ls);
    else change(posi,tr[now].rs);
    tr[now].num=min(tr[tr[now].ls].num,tr[tr[now].rs].num);
}

int main()
{
    scanf("%d",&n);n--;
    scanf("%lld %lld",&n1,&n2);
    for(i=1;i<=n;i++)scanf("%lld %lld",&a[i].t,&a[i].w);
    sort(a+1,a+n+1,cmp);
    a[0].t=2e18;
    k=1;mt(1,n);
    ans=find(n1);
    if(ans==1){printf("1");return 0;}
    m=0;
    while(m<n && n1>0)
    {
        int e=find(n1);
        pp tt=search(1,e-1,1);
        if(tt.num<=n1)
        {
            m++;
            n1-=tt.num;
            change(tt.pos,1);
            ans=min(ans,find(n1)-m);
        }else break;
    }
    printf("%d",ans);
    return 0;
}