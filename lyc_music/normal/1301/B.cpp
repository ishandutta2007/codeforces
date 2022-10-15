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
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}\
int T,n,a[100005];
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		int s=0,ans=0;vector<int>g;
		for (int i=1;i<=n;i++) 
		{
			a[i]=read();
		}
		for (int i=1;i<=n;i++)
		{
			if (i!=1&&(a[i]!=-1)&&(a[i-1]==-1))g.push_back(a[i]);
			else
			if (i!=n&&(a[i]!=-1)&&(a[i+1]==-1))g.push_back(a[i]);
			
			if (i!=1&&a[i]!=-1&&a[i-1]!=-1) ans=max(ans,abs(a[i]-a[i-1]));
		}
		sort(g.begin(),g.end());
		if (g.size()==0)
		{
			writesp(0),writesp(0);
		} else
		{
		int now=(g[0]+g[g.size()-1])/2;
//		cout<<now<<endl;
//		cout<<g[0]<<" "<<g[g.size()-1]<<endl;
		for (int i=1;i<=n;i++) 
			if (a[i]==-1) a[i]=now;
		for (int i=2;i<=n;i++)
			ans=max(ans,abs(a[i]-a[i-1]));
		writesp(ans),writesp(now);}
		puts("");
	}
}
/*

*/