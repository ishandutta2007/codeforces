//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
//#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,q,m,opt,l,r;
char ch;
string st,st1;
int ans;
int u;
struct node
{
	int sm[10];
	node(){memset(sm,0,sizeof(sm));}
};
struct sgt
{
	node c[N<<2];
	int tag[N<<2];
	inline void init()
	{
		memset(tag,0,sizeof(tag));
	}
	inline void pushup(int k)
	{
		for (int i=0;i<m;i++)
		{	
			c[k].sm[i]=c[k<<1].sm[i]+c[k<<1|1].sm[i];
		}
	}
	inline void pushdown(int k,int l,int r)
	{
		if (!tag[k]) return;
		tag[k<<1]=tag[k];
		tag[k<<1|1]=tag[k];
		for (int i=0;i<m;i++)
		{
			c[k<<1].sm[i]=c[k<<1|1].sm[i]=0;
		}
		if (tag[k]!=-1)
		{
			int mid=(l+(r-l)/2);
			c[k<<1].sm[tag[k]-1]=mid-l+1,c[k<<1|1].sm[tag[k]-1]=r-mid;
		}
		tag[k]=0;
	}
	void update(int k,int l,int r,int L,int R,int val)
	{
		if (R<L) return;
		if (L<=l&&r<=R)
		{
//			cout<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<val<<endl;
			for (int i=0;i<m;i++) c[k].sm[i]=0;
			if (val!=-1)
			{
				c[k].sm[val]=r-l+1;
				tag[k]=val+1;
			} else tag[k]=-1;
			return;
		}
		pushdown(k,l,r);
		int mid=l+(r-l)/2;
		if (L<=mid) update(k<<1,l,mid,L,R,val);
		if (R>mid) update(k<<1|1,mid+1,r,L,R,val);
		pushup(k);
	}
	inline node merge(node x,node y)
	{
		for (int i=0;i<m;i++) x.sm[i]+=y.sm[i];
		return x;
	}
	node query(int k,int l,int r,int L,int R)
	{
		if (R<L) return node();
		if (L<=l&&r<=R) return c[k];
		pushdown(k,l,r);
		int mid=l+(r-l)/2;
		node res;
		if (L<=mid) res=merge(res,query(k<<1,l,mid,L,R));
		if (R>mid) res=merge(res,query(k<<1|1,mid+1,r,L,R));
		return res;
	}
}tr[10];
int tr1[N<<2],tag1[N<<2];
int f[15][15];
inline void pushdown1(int k)
{
	if (!tag1[k]) return;
	tr1[k<<1]=tr1[k<<1|1]=tag1[k]-1,tag1[k<<1]=tag1[k<<1|1]=tag1[k];
	tag1[k]=0;
}
void updatech(int k,int l,int r,int L,int R,int val)
{
	if (L<=l&&r<=R)
	{
		tr1[k]=val;
		tag1[k]=val+1;
		return;
	}
	int mid=l+(r-l)/2;
	pushdown1(k);
	if (L<=mid) updatech(k<<1,l,mid,L,R,val);
	if (R>mid) updatech(k<<1|1,mid+1,r,L,R,val);
}
int querych(int k,int l,int r,int L)
{
	if (l==r) return tr1[k];
	int mid=l+(r-l)/2;
	pushdown1(k);
	if (L<=mid) return querych(k<<1,l,mid,L);
	return querych(k<<1|1,mid+1,r,L);
}
signed main()
{
//	freopen("mahoushoujo.in","r",stdin);
//	freopen("mahoushoujo.out","w",stdout);
	IOS;
	cin>>n>>q>>m;
	cin>>st;
	st=' '+st;
	for (int i=0;i<m;i++) tr[i].init();
	for (int i=1;i<n;i++)
	{
		tr[st[i]-'a'].update(1,1,n,i,i,st[i+1]-'a');
	}
	for (int i=1;i<=n;i++) updatech(1,1,n,i,i,st[i]-'a');
	while (q--)
	{
		cin>>opt;
		if (opt==1)
		{
			cin>>l>>r;
			cin>>ch;
			for (int i=0;i<m;i++) tr[i].update(1,1,n,l,r,-1);
			tr[ch-'a'].update(1,1,n,l,r-1,ch-'a');
			updatech(1,1,n,l,r,ch-'a');
//			cout<<"?"<<ch-'a'<<endl;
			if (l>1)
			{
				u=querych(1,1,n,l-1);
//				cout<<"fnd "<<u<<endl;
				tr[u].update(1,1,n,l-1,l-1,ch-'a');
			} 
			if (r<n)
			{
				u=querych(1,1,n,r+1);
//				cout<<"upd "<<u<<endl;
				tr[ch-'a'].update(1,1,n,r,r,u);
			}
		}
		else
		{
			l=1,r=n;
			ans=0;
			cin>>st1;
			for (int i=0;i<m;i++)
				for (int j=0;j<m;j++) f[i][j]=0;
			for (int i=0;i<m;i++)
				for (int j=0;j<=i;j++)
					f[st1[i]-'a'][st1[j]-'a']=1;
			for (int i=0;i<m;i++)
			{
				node now=tr[i].query(1,1,n,l,r-1);
				for (int j=0;j<m;j++)
				{
//					cout<<f[i][j]<<","<<now.sm[j]<<" ";
					ans=ans+f[i][j]*now.sm[j];
				}
//				cout<<endl;
			}
			cout<<ans+1<<endl;
		}
	}
}
/*
7 4 3
abacaba
2 1 7 abc
1 3 5 b
1 4 4 c
2 3 6 cba

7 4 3
abacaba
1 3 5 b
2 1 7 abc
1 4 4 c
2 3 6 cba
*/