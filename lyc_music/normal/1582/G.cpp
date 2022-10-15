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
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int v[N],pr[N],l[N];
string st;
int a[N];
int n;
int ans;
int sta[N];
vector<int>g[N];
int tp,cnt;
void work()
{
	for (int i=2;i<=n;i++)
	{
		if (!v[i])
		{
			v[i]=i;
			pr[++cnt]=i;
		}
		for (int j=1;pr[j]*i<=n;j++)
		{
			v[pr[j]*i]=pr[j];
			if (i%pr[j]==0) break;
		}
	}
}
void ad(int x,int y)
{
	l[x]=x;
	for (int i=v[y];y!=1;i=v[y/=i])
		g[i].push_back(x);
//		cout<<"ad "<<i<<" "<<x<<endl;
}
void del(int x,int y)
{
	l[x]=x;
	for (int i=v[y];y!=1;i=v[y/=i])
	{
		if (g[i].size()==0)
		{
			l[x]=0;
			return;
		}
		l[x]=min(l[x],g[i].back());
		g[i].pop_back();
//		cout<<"?"<<i<<" "<<x<<endl;
	}
}
	
signed main()
{
	IOS;
	n=1e6;
	work();
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	cin>>st;
	st=' '+st;
	for (int i=1;i<=n;i++)
	{
		if (st[i]=='*') ad(i,a[i]);
		else del(i,a[i]);
	}
	l[n+1]=-1;
	sta[++tp]=n+1;
	for (int i=n;i>=1;i--)
	{
		while (tp&&l[sta[tp]]>=l[i])
		{
			tp--;
		}
		if (l[i]==i)
			ans+=sta[tp]-i;
		sta[++tp]=i;
	}
	writeln(ans);
}
/*

*/