//~~
#pragma GCC optimize(2,3,"Ofast")
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1000000000
#define mod 998244353
//#define int ll
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
//#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int c[N];
int lson[N*50],rson[N*50],tr[N*50];
int n,q,a[N];
vector<pa>Q[N];
int rt;
int sta[N],tp;
int cnt;
int ans[N];
void clrc()
{
	for (int i=1;i<=n;i++) c[i]=inf;
}
void clrtr()
{
	rt=0;
	cnt=0;
}
void pushup(int k)
{
	tr[k]=max(tr[lson[k]],tr[rson[k]]);
}
void update(int &k,int l,int r,int x,int val)
{
	if (!k) k=++cnt,tr[k]=0,lson[k]=rson[k]=0;
	// cout<<l<<" "<<r<<endl;
	if (l==r)
	{
		tr[k]=max(tr[k],val);
		return;
	}
	int mid=l+(r-l)/2;
	if (x<=mid) update(lson[k],l,mid,x,val);
	if (x>mid) update(rson[k],mid+1,r,x,val);
	pushup(k);
}
int query(int k,int l,int r,int L,int R)
{
//	 cout<<" "<<k<<" "<<l<<" "<<r<<" "<<x<<endl;
	if (!k) return 0;
	if (L<=l&&r<=R) 
	{
//		cout<<"?"<<k<<" "<<tr[k]<<" "<<l<<" "<<r<<endl;
		return tr[k];
	}
	int res=0;
	int mid=l+(r-l)/2;
	if (L<=mid) res=max(res,query(lson[k],l,mid,L,R));
	if (R>mid) res=max(res,query(rson[k],mid+1,r,L,R));
	return res;
}	
void update(int x,int y)
{
	while (x<=n) c[x]=min(c[x],y),x+=(x&-x);
}
int query(int x)
{
	int res=inf;
	while (x) res=min(res,c[x]),x-=(x&-x);
	return res;
}
void BellaKira()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read();
	q=read();
	for (int i=1;i<=q;i++)
	{
		int l=read(),r=read();
		Q[r].push_back(mp(i,l));
		ans[i]=inf;
	}
	clrc();
	clrtr();
	tp=0;
	for (int i=1;i<=n;i++)
	{
//		 cout<<i<<endl;
		while (tp&&a[sta[tp]]<a[i])
		{
			tp--;
		}
		if (tp)
		{
			int x=sta[tp];
			while (x)
			{
//				cout<<"??"<<i<<" "<<x<<" "<<a[x]<<" "<<a[i]<<" "<<(a[x]+a[i]-1)/2<<endl;
				update(n-x+1,a[x]-a[i]);
				x=query(rt,0,inf,a[i],(a[x]+a[i]-1)/2);
//				cout<<"!!!"<<x<<endl;
			}
		}
		sta[++tp]=i;
		for (auto u:Q[i])
		{
			ans[u.fi]=min(ans[u.fi],query(n-u.se+1));
		}
		update(rt,0,inf,a[i],i);
	}
	
//	for (int i=1;i<=q;i++)writeln(ans[i]);
	// return;
	for (int i=1;i<=n;i++) a[i]=inf-a[i];
	clrc();
	clrtr();
	tp=0;
	for (int i=1;i<=n;i++)
	{
		while (tp&&a[sta[tp]]<a[i])
		{
			tp--;
		}
		if (tp)
		{
			int x=sta[tp];
			while (x)
			{
//				cout<<"??"<<i<<" "<<x<<" "<<a[x]<<" "<<a[i]<<" "<<(a[x]+a[i]-1)/2<<endl;
				update(n-x+1,a[x]-a[i]);
				x=query(rt,0,inf,a[i],(a[x]+a[i]-1)/2);
			}
		}
		sta[++tp]=i;
		for (auto u:Q[i])
		{
			ans[u.fi]=min(ans[u.fi],query(n-u.se+1));
		}
		update(rt,0,inf,a[i],i);
	}
	for (int i=1;i<=q;i++)writeln(ans[i]);
				
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}
/*

*/