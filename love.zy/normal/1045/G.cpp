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
 
struct robot
{
    int x,r,s;
    void read(){scanf("%d%d%d",&x,&r,&s);}
    bool operator < (const struct robot &p){return r>p.r;}
}a[100005];

struct node
{
    int ls,rs,sum,lg,rg;
    void clear(int ll,int rr){ls=rs=sum=0;lg=ll;rg=rr;}
}tr[5000005];
int nodecnt = 0;

int newnode(int l,int r)
{
    nodecnt ++;
    tr[nodecnt].clear(l,r);
    return nodecnt;
}

void addrobot(int ro, int pos)
{
    if(tr[ro].lg==tr[ro].rg)
    {
        tr[ro].sum++;
        return;
    }
    int mid=(tr[ro].lg+tr[ro].rg)>>1;
    if(pos<=mid)
    {
        if(tr[ro].ls==0)tr[ro].ls=newnode(tr[ro].lg, mid);
        addrobot(tr[ro].ls, pos);
    }else
    {
        if(tr[ro].rs==0)tr[ro].rs=newnode(mid+1 ,tr[ro].rg);
        addrobot(tr[ro].rs, pos);
    }
    tr[ro].sum=tr[tr[ro].ls].sum+tr[tr[ro].rs].sum;
}

int query(int ro, int ll, int rr)
{
    if(ro==0)return 0;
    if(tr[ro].lg>=ll && tr[ro].rg<=rr)return tr[ro].sum;
    int mid=(tr[ro].lg+tr[ro].rg)>>1;
    int ret=0;
    if(ll<=mid)ret+=query(tr[ro].ls, ll, min(rr,mid));
    if(rr>mid)ret+=query(tr[ro].rs, max(ll,mid+1), rr);
    return ret;
}

int lsh[100005],ls[100005],c;
int n,m,root[100005];
LL ans=0;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)a[i].read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)lsh[i]=a[i].s;
    sort(lsh+1,lsh+n+1);
    ls[c=1]=lsh[1];
    for(int i=2;i<=n;i++)if(lsh[i]!=lsh[i-1])ls[++c]=lsh[i];
    for(int i=1;i<=c;i++)root[i]=newnode(0,1e9);
    for(int i=1;i<=n;i++)
    {
        int lb=lower_bound(ls+1,ls+c+1,a[i].s)-ls;
        int j=lb;
        while(j>0 && ls[j]+m>=ls[lb])
        {
            ans+=1ll*query(root[j], max(0,a[i].x-a[i].r), min((int)1e9, a[i].x+a[i].r));
            j--;
        }
        j=lb+1;
        while(j<=c && ls[lb]+m>=ls[j])
        {
            ans+=1ll*query(root[j], max(0,a[i].x-a[i].r), min((int)1e9, a[i].x+a[i].r));
            j++;
        }
        addrobot(root[lb], a[i].x);
    }
    printf("%lld\n",ans);
    return 0;
}