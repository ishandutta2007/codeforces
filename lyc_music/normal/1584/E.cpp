//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 500005
using namespace std;
using namespace __gnu_pbds;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
map<ll,tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> >S[2];
int n,x,a[N],s[N],ans,b[N],sta[2][N],tp[2];
int query1(int n1,int x)
{
	int l=1,r=n1+1,res=0;
	while(l<r)
	{
		int mid=l+(r-l)/2;
		if(s[sta[0][mid]]<x)
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	if (!res) return n;
	return sta[0][res];
}
int query2(int n1,int x)
{
	int l=1,r=n1+1,res=0;
	while(l<r)
	{
		int mid=l+(r-l)/2;
		if(s[sta[1][mid]]<x)
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid;
		}
	}
	if (!res) return n;
	return sta[1][res];
}
void LYC_music()
{
	n=read();
	for(int i=1;i<=n;++i)
	{
		a[i]=read();
		s[i]=-s[i-1]+a[i];
	}
	tp[0]=tp[1]=0;
	ans=0;
	int x=0;
	for(int i=n;i>=1;--i)
	{
		while(tp[x]&&s[i]<=s[sta[x][tp[x]]]) tp[x]--;
		sta[x][++tp[x]]=i;
		S[x][s[i]].insert(i);
		x^=1;
		int pp=0,pq=0;
		if (x==0) 
			pp=query1(tp[x],s[i-1]);
		else 
			pp=query2(tp[x],s[i-1]);
		if (x==0)
			pq=query2(tp[x^1],-s[i-1]);
		else 
			pq=query1(tp[x^1],-s[i-1]);
			
		pp=min(pp,pq);
		ans+=S[x][s[i-1]].order_of_key(pp+1);
		ans+=S[x^1][-s[i-1]].order_of_key(pp+1);
	}
	writeln(ans);
	S[0].clear(),S[1].clear();
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