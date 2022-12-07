/*****************************
Author : lizi
Email  : zyli@smail.nju.edu.cn
*****************************/

#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double pi=3.1415926535897932384626;
const double eln=2.718284590452353602874;
#define IN freopen("tmp.in", "r", stdin);
#define OU freopen("tmp.ou", "w", stdout);
#define mp make_pair
#define pb push_back
#define pr1(x) printf("Case %d: ", x);
#define pn1(x) printf("Case %d:\n",x);
#define pr2(x) printf("Case #%d: ", x);
#define pn2(x) printf("Case #%d:\n",x);
#define sqr(x) (x)*(x)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
typedef long long LL;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int maxn=200005;
struct wcy
{
    int l,r,c,p;
    void read(){scanf("%d%d%d%d",&l,&r,&c,&p);}
}rg[maxn];
vi gin[1000005],gout[1000005];
struct node
{
    int ls,rs,lg,rg;
    LL sum,cnt;
    void clear(){ls=rs=lg=rg=0;sum=cnt=0;}
    void init(int l,int r){lg=l;rg=r;}
}tr[maxn<<2];

int lsh[maxn],ls[maxn],lsc,n,m,k,nodecnt;
void lsh_func()
{
    sort(lsh+1,lsh+m+1);
    ls[lsc=1]=lsh[1];
    for(int i=2;i<=m;i++)
        if(lsh[i]!=lsh[i-1])ls[++lsc]=lsh[i];
}

void mt(int x,int y)
{
    tr[nodecnt].init(x,y);
    if(x==y)return;
    int mid=(x+y)>>1,t=nodecnt;
    nodecnt++;tr[t].ls=nodecnt;mt(x,mid);
    nodecnt++;tr[t].rs=nodecnt;mt(mid+1,y);
}

void pushup(int t)
{
    if(tr[t].ls==0)return;
    int ls=tr[t].ls,rs=tr[t].rs;
    tr[t].cnt=tr[ls].cnt+tr[rs].cnt;
    tr[t].sum=tr[ls].sum+tr[rs].sum;
}

void add(int now,int pos,LL num)
{
    if(tr[now].ls==0)
    {
        tr[now].cnt+=num;
        tr[now].sum+=ls[pos]*num;
        return;
    }
    int mid=(tr[now].lg+tr[now].rg)>>1;
    if(pos<=mid)add(tr[now].ls,pos,num);
    else add(tr[now].rs,pos,num);
    pushup(now);
}

pair<LL,LL> query(int now,LL num)
{
    if(num<=0)return mp(0ll,0ll);
    if(tr[now].cnt<=num) return mp(tr[now].sum, tr[now].cnt);
    if(tr[now].ls==0) return mp(num*ls[tr[now].lg],num);
    pair<LL,int> s1,s2;
    s1=query(tr[now].ls,num);
    //if(tr[tr[now].ls].cnt>=num)return s1;
    s2=query(tr[now].rs,num-tr[tr[now].ls].cnt);
   /* if(tr[tr[tr[now].ls].cnt]>=num) return query(tr[now].ls,num);
    else
    {
        pair<LL, int> s1,s2;
        s1=query(tr[now].ls,tr[tr[now].ls].cnt);
        s2=query(tr[now].ls,num-tr[tr[now].ls].cnt);
        return mp(s1.fi+s2.fi,s1.se+s2.se);
    }*/
    return mp(s1.fi+s2.fi,s1.se+s2.se);
}

int main()
{
    scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++)
    {
        rg[i].read();
        lsh[i]=rg[i].p;
        gin[rg[i].l].pb(i);
        gout[rg[i].r].pb(i);
    }
    lsh_func();
    for(int i=1;i<=m;i++)rg[i].p=lower_bound(ls+1,ls+lsc+1,rg[i].p)-ls;
    nodecnt=1;mt(1,lsc);
    LL ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int p : gin[i]) add(1,rg[p].p,rg[p].c);
        ans+=query(1,k).fi; 
        //printf("%d %lld\n",i,query(1,k).fi);
        for(int p : gout[i]) add(1,rg[p].p,-rg[p].c);
    }
    printf("%lld\n",ans);
    return 0;
}