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
//#define int ll
//#define N
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int T,a[200005];
int n;
multiset<pair<int,int>>S;
signed main()
{
	T=read();
	while (T--)
	{
		vector<pa>ans;
		n=read();
		for (int i=1;i<=n;i++)
		{
			a[i]=read();
			if (a[i])	S.insert({a[i],i});
		}
		for (int i=1;i;i++)
		{
//			cout<<i<<endl;	
			while (S.size()&&(*S.begin()).fi==0) S.erase(S.begin());
			if (S.size()<=1) break;
			ans.push_back({(*S.rbegin()).se,(*S.begin()).se});
			auto u=(*--S.end()),v=(*S.begin());
			S.erase(u),S.erase(v);
			u.fi--,v.fi--;
			S.insert(u),S.insert(v);
		}
		writeln(ans.size());
		for (auto u:ans) writesp(u.fi),writeln(u.se);
		S.clear();
	}
}
/*

*/