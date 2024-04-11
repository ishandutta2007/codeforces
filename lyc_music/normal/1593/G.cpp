//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 1000005
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,s[N],q,l,r,x;
int a[N];
string st;
pa tr[N<<2];
pa merge(pa x,pa y)
{
	if (y.fi==0) return x;
	if (x.fi==0) return y;
	if (x.se==y.se^(y.fi%2))
	{
		return {x.fi+y.fi,y.se};
	}
	if (x.fi==y.fi) return {0,0};
	if (x.fi>y.fi)
		return {x.fi-y.fi,x.se^(y.fi%2)};
	return {y.fi-x.fi,y.se};
}	
void build(int k,int l,int r)
{
	if (l==r)
	{
		tr[k]={1,a[l]};
		return;
	}
	int mid=l+(r-l)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	tr[k]=merge(tr[k<<1],tr[k<<1|1]);
//	cout<<l<<" "<<r<<" "<<tr[k].fi<<" "<<tr[k].se<<endl;
}
pa query(int k,int l,int r,int L,int R)
{
	if (L<=l&&r<=R)
	{
		return tr[k];
	}
	int mid=l+(r-l)/2;
	if (R<=mid) return query(k<<1,l,mid,L,R);
	if (L>mid) return query(k<<1|1,mid+1,r,L,R);
	return merge(query(k<<1,l,mid,L,R),query(k<<1|1,mid+1,r,L,R));
}
signed main()
{
	IOS;
	cin>>T;
	while (T--)
	{
		cin>>st;
		n=st.length();
		st=' '+st;
		for (int i=1;i<=n;i++)
		{
			if (st[i]==']') st[i]='[';
			else if (st[i]==')') st[i]='(';
			if (st[i]=='[') a[i]=1;
			else a[i]=0;
		}
		build(1,1,n);
		cin>>q;
		while (q--)
		{
			cin>>l>>r;
			pa u=query(1,1,n,l,r);
			int ans=u.fi/2;
			if (u.fi%2==1&&u.se==1) ans++;
			cout<<ans<<endl;
		}
	}		
}
/*

*/