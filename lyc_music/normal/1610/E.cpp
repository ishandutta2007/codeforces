//The Hunting Party - Keys To The Kingdom
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
//#define N
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
set<pa>S;
int n,a[200005];
void LYC_music()
{
	n=read();
	int ans=0;
	S.clear();
	for (int i=1;i<=n;i++)
	{
		a[i]=read();
		S.insert({a[i],i});
	}
	ans=n;
	int lst=0;
	for (int i=1;i<n;i++)
	{
		if (a[i+1]==a[i])
		{
			lst++;
			continue;
		}
		int x=a[i+1]-a[i];
		int now=2;
		int y=i+1;
		while (1)
		{
			auto it=S.upper_bound({a[i]+2*x,y});
			if (it==S.end()) break;
			x=(*it).fi;
			y=(*it).se;
//			cout<<x<<" "<<y<<endl;
			x-=a[i];
			now++;
//			cout<<x<<" "<<y<<endl;
		}
//		cout<<"?"<<i<<" "<<now<<endl;
		ans=min(ans,n-now-lst);
		lst=0;
	}
	lst++;
	ans=min(ans,n-lst);
	writeln(ans);
}
signed main()
{
	int T=read();
	while (T--)
	{
		LYC_music();
	}
}
/*

*/