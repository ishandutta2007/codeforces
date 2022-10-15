//QwQcOrZ yyds!!!
#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define re register
#define inf 1e18
#define mod 998244353
#define int ll
#define N 105
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,n,a[N],b[N];
map<int,int>c,Mp;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();
		vector<pair<int,pa>>ans;
		for (int i=1;i<=n;i++) a[i]=read(),b[i]=a[i];
		sort(b+1,b+n+1);
		for (int i=1;i<=n;i++) 
		{
			int x=lower_bound(b+1,b+n+1,a[i])-b+Mp[a[i]];
			Mp[a[i]]++;
			a[i]=x;
			c[x]=i;
		}
		for (int i=1;i<=n;i++) b[i]=a[i];
		sort(b+1,b+n+1);
		for (int i=1;i<=n;i++)
		{
			if (i!=c[b[i]])
				ans.push_back({i,{c[b[i]],c[b[i]]-i}});
			for (int j=1;j<=c[b[i]]-i;j++)
			{
				int y=a[i];
				for (int k=i;k<=c[b[i]]-1;k++) a[k]=a[k+1];
				a[c[b[i]]]=y;
			}	
			for (int j=1;j<=n;j++)
				c[a[j]]=j;
		}
//		cout<<"!"<<endl;
		writeln(ans.size());
		for (auto u:ans) writesp(u.fi),writesp(u.se.fi),writeln(u.se.se);
		Mp.clear();
		c.clear();
	}	
}
/*

*/