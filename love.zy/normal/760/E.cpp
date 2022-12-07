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
 
const int maxn=100005;

struct tree
{
	int mi,ls,rs,ll,rr,add;
}a[3*maxn];

int b[maxn];
int k,n;

void update(int x)
{
	if(a[x].ls+a[x].rs==0)return;
	a[x].mi=max(a[a[x].ls].mi,a[a[x].rs].mi);
}

void downdate(int x)
{
	if(a[x].ls+a[x].rs==0)return;
	if(a[x].add==0)return;
	a[a[x].ls].add+=a[x].add;
	a[a[x].ls].mi+=a[x].add;
	a[a[x].rs].add+=a[x].add;
	a[a[x].rs].mi+=a[x].add;
	a[x].add=0;
}

void mt(int l,int r)
{
	if(l==r)
	{
		a[k].ll=a[k].rr=l;
		a[k].mi=0;
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

void add(int l,int r,int nu,int x)
{
	if(a[x].ll==l && a[x].rr==r)
	{
		a[x].add+=nu;
		a[x].mi+=nu;
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

int find(int l,int r,int x)
{
	if(a[x].ll==l && a[x].rr==r)return a[x].mi;
	downdate(x);
	update(x);
	int mid=(a[x].ll+a[x].rr)>>1;
	if(mid<l)return find(l,r,a[x].rs);
	if(mid>=r)return find(l,r,a[x].ls);
	return max(find(l,mid,a[x].ls),find(mid+1,r,a[x].rs));
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
	read(n);
	k=1;mt(1,n);
    int u=0;
    while(n--)
    {
        int p,c,m;
        read(p);read(c);
        if(c==1)read(m);
        b[p]=m;u=max(p,u);
        if(c==1)add(1,p,1,1);else add(1,p,-1,1);
        int l=1,r=u;
        if(find(1,u,1)<=0){printf("-1\n");continue;}
        while(r-l>1)
        {
            int mid=(l+r)>>1;
            if(find(mid,u,1)>=1)l=mid;else r=mid;
        }
        if(find(r,u,1)<1)r--;
        printf("%d\n",b[r]);
    }
	return 0;
}