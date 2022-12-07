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
  
const LL mod=1e9+7;
const int maxn=100005;

struct mat
{
    int n;
    LL num[3][3];
    
    bool law1()
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(i!=j && num[i][j]!=0)return false;
                if(i==j && num[i][j]!=1)return false;
            }
        return true;
    }

    void init0(int t)
    {
        n=t;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                num[i][j]=0;
    }

    void init1(int t)
    {
        n=t;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                if(i!=j)num[i][j]=0;else num[i][j]=1;
    }
    
    mat operator + (const struct mat p)const
    {
        struct mat q;
        q.init0(n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                q.num[i][j]=(num[i][j]+p.num[i][j])%mod;
        return q;
    }

    mat operator * (const struct mat p)const
    {
        struct mat ans;
        ans.init0(n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    ans.num[i][j]=(ans.num[i][j]+num[i][k]*p.num[k][j])%mod;
        return ans;
    }       

    mat operator ^ (int t)const
    {
        struct mat ans,now;
        ans.init1(n);
        now.n=n;
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                now.num[i][j]=num[i][j];
        while(t>0)
        {
            if(t&1)ans=ans*now;
            now=now*now;
            t>>=1;
        }
        return ans;
    }

}c[maxn];

struct tree
{
	int ls,rs,ll,rr;
    struct mat mi,add;
}a[3*maxn];

int i,j,k,l,m,n,t,T;

void update(int x)
{
	if(a[x].ls+a[x].rs==0)return;
	a[x].mi=a[a[x].ls].mi+a[a[x].rs].mi;
}

void downdate(int x)
{
	if(a[x].ls+a[x].rs==0)return;
	if(a[x].add.law1())return;
	a[a[x].ls].add=a[a[x].ls].add*a[x].add;
	a[a[x].ls].mi=a[a[x].ls].mi*a[x].add;
	a[a[x].rs].add=a[a[x].rs].add*a[x].add;
	a[a[x].rs].mi=a[a[x].rs].mi*a[x].add;
	a[x].add.init1(2);
}

void mt(int l,int r)
{
	a[k].add.init1(2);
    if(l==r)
	{
		a[k].ll=a[k].rr=l;
		a[k].mi=c[l];
		a[k].ls=a[k].rs=0;
		return;
	}
	int t=k;
	int mid=(l+r)>>1;
	a[t].ll=l;a[t].rr=r;
	k++;a[t].ls=k;mt(l,mid);
	k++;a[t].rs=k;mt(mid+1,r);
	update(t);
}

void add(int l,int r,mat nu,int x)
{
	if(a[x].ll==l && a[x].rr==r)
	{
		a[x].add=a[x].add*nu;
		a[x].mi=a[x].mi*nu;
		return;
	}
	downdate(x);
	int mid=(a[x].ll+a[x].rr)>>1;
	if(mid<l)add(l,r,nu,a[x].rs);
	else if(mid>=r)add(l,r,nu,a[x].ls);
	else
	{
		add(l,mid,nu,a[x].ls);
		add(mid+1,r,nu,a[x].rs);
	}
	update(x);
}

mat find(int l,int r,int x)
{
	if(a[x].ll==l && a[x].rr==r)return a[x].mi;
	downdate(x);
	update(x);
	int mid=(a[x].ll+a[x].rr)>>1;
	if(mid<l)return find(l,r,a[x].rs);
	if(mid>=r)return find(l,r,a[x].ls);
	return find(l,mid,a[x].ls)+find(mid+1,r,a[x].rs);
}

inline void read(int &x) {
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    x=0;
    while(ch<='9'&&ch>='0'){
        x=x*10+ch-'0';
        ch=getchar();
    }
}

int main()
{
	struct mat unit;
    unit.init0(2);
    unit.num[1][1]=unit.num[1][2]=unit.num[2][1]=1;
    unit.num[2][2]=0;
    read(n);read(m);
	for(i=1;i<=n;i++)
    {
        read(k);
        c[i]=unit^(k-1);
    }
	k=1;mt(1,n);
	for(i=1;i<=m;i++)
	{
		read(j);
        if(j==1)
        {
            read(j);read(k);read(l);
            add(j,k,unit^l,1);
        }else
        {
            read(j);read(k);
            struct mat ans=find(j,k,1);
            printf("%lld\n",ans.num[1][1]);
        }
    }
	return 0;
}