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
int n,a[N],f[N],b[N];
int B=8192;
vector<int>ans;
signed main()
{
	n=read();
	for (int i=1;i<=n;i++) a[i]=read();
	for (int i=0;i<B;i++) f[i]=B-1;
	f[0]=-1;
	for (int i=1;i<=n;i++)
	{
		if (b[a[i]]) continue;
		b[a[i]]=1;
//		cout<<i<<endl;
		for (int j=0;j<B;j++)
			if (f[j]<a[i]&&a[i]<f[j^a[i]])
			{
//				cout<<i<<" "<<j<<" "<<endl;
				for (int k=a[i]+1;k<=f[j^a[i]];k++) b[k]=0;
//				cout<<i<<" "<<j<<" "<<endl;
				f[j^a[i]]=a[i];
			}
	}
	for (int i=0;i<B;i++)
		if (f[i]!=B-1) 
			ans.push_back(i);
	writeln(ans.size());
	for (auto u:ans) writesp(u);
		
}
/*

*/