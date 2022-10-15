//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 1000000007
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int tr[N<<2],tag[N<<2];
int x[N],y[N],X[N],Y[N];
int n,m,K;
vector<int>g[N],A[N],E[N];
set<int>S;
void ad(int &x,int y)
{
	x=(x+y)%mod;
}
bool cmp(int i,int j)
{
	return Y[i]>Y[j];
}
void pushdown(int k)
{
	if (!tag[k]) return;
	tag[k<<1]=tag[k<<1|1]=1;
	tr[k<<1]=tr[k<<1|1]=0;
	tag[k]=0;
}
void pushup(int k)
{
	tr[k]=0;
	ad(tr[k],tr[k<<1]);
	ad(tr[k],tr[k<<1|1]);
}
void update1(int k,int l,int r,int L,int val)
{
	if (l==r)
	{
		ad(tr[k],val);
		return;
	}
	pushdown(k);
	int mid=l+(r-l)/2;
	if (L<=mid) update1(k<<1,l,mid,L,val);
	else update1(k<<1|1,mid+1,r,L,val);
	pushup(k);
}
void update(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R)
	{
		tr[k]=0;
		tag[k]=1;
		return;
	}
	pushdown(k);
	int mid=l+(r-l)/2;
	if (L<=mid) update(k<<1,l,mid,L,R);
	if (R>mid) update(k<<1|1,mid+1,r,L,R);
	pushup(k);
}
int query(int k,int l,int r,int L,int R)
{
	if (R<L) return 0;
	if (L<=l&&r<=R) return tr[k];
	pushdown(k);
	int mid=l+(r-l)/2,res=0;
	if (L<=mid) ad(res,query(k<<1,l,mid,L,R));
	if (R>mid) ad(res,query(k<<1|1,mid+1,r,L,R));
	pushup(k);
	return res;
}
signed main()
{
//	freopen("michael.in","r",stdin);
//	freopen("michael.out","w",stdout);
	n=read(),m=read(),K=read();
	for (int i=1;i<=K;i++)
	{
		x[i]=read(),y[i]=read(),X[i]=read(),Y[i]=read();
		g[x[i]].push_back(i);
		A[x[i]].push_back(y[i]);
		E[X[i]+1].push_back(y[i]);
		A[x[i]].push_back(Y[i]);
		E[X[i]+1].push_back(Y[i]);
	}
	update1(1,1,m,1,1);
	S.insert(0);
	for (int i=1;i<=n;i++)
	{
		sort(g[i].begin(),g[i].end(),cmp);
		for (auto u:g[i])
		{
			if (Y[u]+1>m) continue;
			int p=(*(--S.upper_bound(Y[u]+1)));
			if (p<Y[u])
			{
//				cout<<"?"<<u<<" "<<p<<" "<<y[u]<<" "<<Y[u]+1<<" "<<query(1,1,m,p+1,Y[u])<<endl;
				if (i!=1) 
				update1(1,1,m,Y[u]+1,query(1,1,m,p+1,Y[u]));
			}
		}
		for (auto u:g[i])
		{
			update(1,1,m,y[u],Y[u]);
		}
		for (auto u:E[i])
		{
			S.erase(u);
		}
		for (auto u:A[i])
		{
			S.insert(u);
		}
	}
	int lst=(*S.rbegin());
//	cout<<lst<<endl;
//	writeln(query(1,1,m,1,1));
	writeln(query(1,1,m,lst+1,m));
}
/*

*/