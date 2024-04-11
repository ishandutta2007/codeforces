/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=200005;
vi g[maxn];
int col[maxn],d[maxn],sz[maxn],ff[maxn];
int n,m,o;

struct segtree
{
    struct node
    {
        int ls,rs,lg,rg,mid;
        int mi,ma,tag;
        void cle(){ls=rs=lg=rg=mid=mi=ma=tag=0;}
        bool one(){return lg==rg;}
        bool judge(int x,int y){return lg==x && rg==y;}
    }tr[500005];
    int k;

    void pushup(int x)
    {
        int ls=tr[x].ls,rs=tr[x].rs;
        if(ls+rs<=0)return;
        tr[x].mi=tr[ls].mi+tr[rs].mi;
        tr[x].ma=tr[ls].ma+tr[rs].ma;
    }
    
    void pushdown(int x)
    {
        int ls=tr[x].ls,rs=tr[x].rs;
        if(ls+rs<=0 || tr[x].tag==0)return;
        int tag=tr[x].tag;
        tr[x].tag=0;
        tr[ls].tag^=tag;tr[rs].tag^=tag;
        swap(tr[ls].mi,tr[ls].ma);
        swap(tr[rs].mi,tr[rs].ma);
        pushup(x);
    }

    void mt(int x,int y)
    {
        tr[k].cle();
        tr[k].lg=x;tr[k].rg=y;
        if(x==y)
        {
            if(col[d[x]])tr[k].ma=1;else tr[k].mi=1;
            return;
        }
        int mid=(x+y)>>1,t=k;
        tr[k].mid=mid;
        k++;tr[t].ls=k;mt(x,mid);
        k++;tr[t].rs=k;mt(mid+1,y);
        pushup(t);
    }
    
    void init(int n){k=1;mt(0,n);}

    void add(int now,int x,int y)
    {
        if(tr[now].judge(x,y))
        {
            tr[now].tag^=1;
            swap(tr[now].ma,tr[now].mi);
            return;
        }
        pushdown(now);
        int mid=tr[now].mid;
        if(x<=mid)add(tr[now].ls,x,min(mid,y));
        if(y>mid)add(tr[now].rs,max(x,mid+1),y);
        pushup(now);
    }

    int query(int now,int x,int y)
    {
        if(tr[now].judge(x,y))return tr[now].ma;
        int mid=tr[now].mid;
        pushdown(now);
        if(y<=mid)return query(tr[now].ls,x,y);
        if(x>mid)return query(tr[now].rs,x,y);
        int ret=0;
        ret+=query(tr[now].ls,x,mid);
        ret+=query(tr[now].rs,mid+1,y);
        return ret;
    }
}segt;

void dfs(int u,int f)
{
    sz[u]=1;
    d[++m]=u;
    ff[u]=m;
    for(int i : g[u])
    {
        dfs(i,u);
        sz[u]+=sz[i];
    }
}

char s[4];

int main()
{
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        g[x].pb(i);
    }
    for(int i=1;i<=n;i++)scanf("%d",&col[i]);
    dfs(1,0);
    segt.mt(1,n);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s%d",s,&o);
        if(s[0]=='g')
            printf("%d\n",segt.query(1,ff[o],ff[o]+sz[o]-1));
        else
            segt.add(1,ff[o],ff[o]+sz[o]-1);
    }
    return 0;
}