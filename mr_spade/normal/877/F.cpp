#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using std::lower_bound;
using std::sort;
using std::unique;
using std::vector;
typedef long long ll;
inline int read()
{
	int res=0,f=0;
	char x;
	while((x=getchar())<'0'||x>'9')
		f|=x=='-';
	for(;x>='0'&&x<='9';x=getchar())
		res=res*10+x-'0';
	return f?-res:res;
}
inline void write(ll x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>=10)
		write(x/10);
	putchar(x%10+'0');
	return;
}
inline void writeln(ll x)
{
	write(x);
	putchar('\n');
	return;
}
const int N=1e5+7;
int n,k,m,unit;
ll res;
int t[N],block[N];
ll sum[N],ans[N];
ll low[N],high[N];
vector<ll> V;
int cnt0[N<<2],cnt1[N<<2];
struct query
{
	int id,l,r;
	inline bool operator<(query th) const
	{
		if(block[l]!=block[th.l])
			return block[l]<block[th.l];
		return r<th.r;
	}
}q[N];
inline void add(int x,bool f)
{
	cnt0[sum[x-1]]++;cnt1[sum[x]]++;
	res+=(f?cnt0[low[x]]:cnt1[high[x]]);
	return;
}
inline void del(int x,bool f)
{
	res-=(f?cnt0[low[x]]:cnt1[high[x]]);
	cnt0[sum[x-1]]--;cnt1[sum[x]]--;
	return;
}
signed main()
{
	//freopen("test.in","r",stdin);
	//freopen("test.out","w",stdout);
	int p=0;
	register int i;
	n=read();k=read();
	unit=ceil(sqrt(n));
	for(i=1;i<=n;i++)
		block[i]=((i-1)%unit?p:++p);
	for(i=1;i<=n;i++)
		t[i]=read();
	V.push_back(0);
	for(i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+((t[i]^1)?-read():read());
		low[i]=sum[i]-k;high[i]=sum[i-1]+k;
		V.push_back(sum[i]);
		V.push_back(low[i]);
		V.push_back(high[i]);
	}
	sort(V.begin(),V.end());
	m=unique(V.begin(),V.end())-V.begin();
	while((int)V.size()>m)
		V.pop_back();
	for(i=0;i<=n;i++)
	{
		sum[i]=lower_bound(V.begin(),V.end(),sum[i])-V.begin();
		low[i]=lower_bound(V.begin(),V.end(),low[i])-V.begin();
		high[i]=lower_bound(V.begin(),V.end(),high[i])-V.begin();
	}
	m=read();
	for(i=1;i<=m;i++)
		q[i].id=i,q[i].l=read(),q[i].r=read();
	sort(q+1,q+m+1);
	int l=1,r=0;
	for(i=1;i<=m;i++)
	{
		for(;l>q[i].l;add(--l,0));
		for(;r<q[i].r;add(++r,1));
		for(;l<q[i].l;del(l++,0));
		for(;r>q[i].r;del(r--,1));
		ans[q[i].id]=res;
	}
	for(i=1;i<=m;i++)
		writeln(ans[i]);
	return 0;
}