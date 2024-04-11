#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<utility>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=200010;
const int MOD=1000000007;
int n,Q,a[MAXN],p[1000010];
vector<int> factors[MAXN];
vector<int> positions[1000010];
LL inv[1000010],ans[MAXN];
LL BIT[MAXN];
LL qpow(LL x,LL n,LL MOD)
{
    LL con=1,p=x;
    while(n)
    {
        if(n&1) con=(con*p)%MOD;
        p=(p*p)%MOD;
        n>>=1;
    }
    return con;
}
inline void Modify(int x,LL tar)
{
    for(int i=x;i<=n;i+=(i&(-i)))
        BIT[i]=(BIT[i]*tar)%MOD;
}
inline LL Query(int l,int r)
{
    LL con1=1,con2=1;
    for(int i=r;i;i^=(i&(-i)))
        con2=(con2*BIT[i])%MOD;
    for(int i=l-1;i;i^=(i&(-i)))
        con1=(con1*BIT[i])%MOD;
    return (con2*qpow(con1,MOD-2,MOD))%MOD;
}
struct QQ
{
    int l,r,id;
    friend bool operator<(const QQ &p,const QQ &q)
    {
        return p.l<q.l;
    }
}q[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q+1,q+Q+1);
    for(int i=1;i<=n;i++)
    {
        int x=a[i];
        for(int k=2;k*k<=a[i];k++)
            if(x%k==0)
            {
                x/=k,factors[i].push_back(k),positions[k].push_back(i);
                while(x%k==0) x/=k;
            }
        if(x>1) factors[i].push_back(x),positions[x].push_back(i);
    }
    for(int i=1;i<=n;i++) BIT[i]=1;
    for(int i=1;i<=n;i++) Modify(i,a[i]);
    for(int i=1;i<=1000000;i++) inv[i]=qpow(i,MOD-2,MOD);
    for(int i=1;i<=1000000;i++)
        if(positions[i].size()>=1) Modify(positions[i][0],((i-1)*inv[i])%MOD);
    int now=1;
    for(int i=1;i<=Q;i++)
    {
        while(q[i].l!=now)
        {
            for(int k=0;k<factors[now].size();k++)
            {
                int x=factors[now][k];
                p[x]++;
                if(p[x]<positions[x].size())
                    Modify(positions[x][p[x]],((x-1)*inv[x])%MOD);
            }
            now++;
        }
        ans[q[i].id]=Query(q[i].l,q[i].r);
    }
    for(int i=1;i<=Q;i++)
        printf("%I64d\n",ans[i]);
    return 0;
}