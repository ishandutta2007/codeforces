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

const int maxn=100005;
struct BIT
{
    LL s[maxn];
    int lim;

    void init(int u)
    {
        lim=u;
        for(int i=1;i<=u;i++)s[i]=0;
    }

    void add(int p,LL nu)
    {
        while(p<=lim)
        {
            s[p]+=nu;
            p+=lowbit(p);
        }
    }

    LL cal(int p)
    {
        LL ret=0;
        while(p>0)
        {
            ret+=s[p];
            p-=lowbit(p);
        }
        return ret;
    }
}bit;

int n,m,k;
int a[maxn],b[maxn],c[maxn],s[maxn],p[maxn];
struct fuck
{
    int c,pos;
    bool operator < (const struct fuck &p)const
    {
        if(c<p.c)return true;
        if(c>p.c)return false;
        return pos>p.pos;
    }
}f[maxn];

int le[maxn];
int find(int t)
{
    if(le[t]==t)return t;
    else return le[t]=find(le[t]);
}

int main()
{
    scanf("%d%d",&n,&m);
    bit.init(n+1);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        bit.add(i,a[i]);
    }
    for(int i=1;i<=m;i++)scanf("%d",&b[i]);
    for(int i=1;i<=m;i++)scanf("%d",&c[i]);
    int now=0;
    for(int i=n;i>=1;i--)
    {
        if(a[i]>0)le[i]=i;else le[i]=i-1;
        if(a[i]<=now)continue;
        now=a[i];
        s[++k]=a[i];
        p[k]=i;
    }
    s[++k]=1e9+7;p[k]=n+1;
    for(int i=1;i<=m;i++)
    {
        int pp=lower_bound(s+1,s+k+1,b[i])-s;
        f[i]={c[i],p[pp]};
        //printf("%d %d\n",i,p[pp]);
    }
    sort(f+1,f+m+1);
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        if(f[i].pos>n || bit.cal(f[i].pos)<f[i].c)continue;
        int now=f[i].c,u=f[i].pos;
        //printf("%d %d ",u,now);
        while(now>0 && u>0)
        {
            u=find(u);
            if(u==0)break;
            LL s=bit.cal(u)-bit.cal(u-1);
            if(now>=s)
            {
                bit.add(u,-s);
                now-=s;
                le[u]=u-1;
            }else
            {
                bit.add(u,-now);
                now=0;
            }
        }
        //printf("%d\n",now);
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}