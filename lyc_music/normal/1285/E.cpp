//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define F(i,a,b) for (int i=(a);i<=(b);i++)
#define R(i,a,b) for (int i=(a);i<(b);i++)
#define D(i,a,b) for (int i=(a);i>=(b);i--)
#define go(i,x) for (int i=head[x];i;i=e[i].nx)
#define mp make_pair
#define pb push_back
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define be begin()
#define en end()
#define sqr(x) ((x)*(x))
#define ret return puts("-1"),0;
#define put putchar('\n')
#define inf 1000000005
#define mod 998244353
#define int ll
#define N 2000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,s[N],d[N],now,ans;
pa a[N];
signed main()
{
	T=read();
	while (T--)
	{
		n=read();now=ans=0;
		vector<int>g;
		for (int i=1;i<=n;i++)
		{
			int l=read(),r=read();
			a[i]={l,r};
			g.push_back(l);
			g.push_back(r);
		}
		sort(g.begin(),g.end());
		for (int i=1;i<=n;i++)
		{
			a[i].fi=lower_bound(g.begin(),g.end(),a[i].fi)-g.begin()+1;
			a[i].se=lower_bound(g.begin(),g.end(),a[i].se)-g.begin()+1;
			a[i].fi=a[i].fi*2-1,a[i].se=a[i].se*2-1;
			s[a[i].fi]++,s[a[i].se+1]--;
//			cout<<a[i].fi<<","<<a[i].se<<endl;
		}
		for (int i=1;i<=4*n;i++) s[i]+=s[i-1];
		s[4*n+1]+=s[4*n];
		for (int i=1;i<=4*n;i++)
		{
			if (s[i]!=0&&s[i-1]==0) now++;
			if (s[i]==1&&s[i+1]>1) d[i]=1;
			d[i]+=d[i-1];
//			cout<<i<<" "<<d[i]<<endl;
		}
		for (int i=1;i<=n;i++)
		{
			int x=d[a[i].se]-d[a[i].fi-1];
			if (s[a[i].fi]==1&&s[a[i].fi-1]==0) x--;
			ans=max(ans,now+x);
//			cout<<i<<" "<<now<<" "<<x<<" "<<d[a[i].se]<<endl;
		}
		for (int i=1;i<=4*n+1;i++) s[i]=d[i]=0;
		writeln(ans);
	}	
}
/*

*/