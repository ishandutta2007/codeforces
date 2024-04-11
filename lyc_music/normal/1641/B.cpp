//~~
#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
#define N 5000005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int m,mm;
pa ans[N];
int ans1[N];
int nowt;
int sm;
int n;
void ins(int x,int y)
{
	ans[++m]=mp(x,y);
}
void ins1(int x)
{
	ans1[++mm]=x;
}
void BellaKira()
{
	n=read();
	map<int,int>Mp;
	vector<int>a(1);
	m=0;mm=0;
//	nowt=1;
	sm=1;
	for (int i=1;i<=n;i++)
	{
		a.push_back(read());Mp[a[i]]^=1;
	}
	for (auto u:Mp)
		if (u.se==1) return puts("-1"),void();
	while (a.size()!=1)
	{
		int now=0;
		for (int i=2;i<(int)a.size();i++) 
			if (a[i]==a[1])
			{
				now=i;
				break;
			}
		for (int i=2;i<now;i++)
		{
			ins(sm+now-1+i-2,a[i]);
		}
		sm+=(now-1)*2;
		a.erase(a.begin()+now);
		a.erase(a.begin()+1);
		reverse(a.begin()+1,a.begin()+now-1);
		ins1((now-1)*2);
	}
	writeln(m);
	for (int i=1;i<=m;i++)
	{
		writesp(ans[i].fi),writeln(ans[i].se);
	}
	writeln(mm);
	for (int i=1;i<=mm;i++) writesp(ans1[i]);
	puts("");
}
signed main()
{
	int T=read();
	while (T--)
	{
		BellaKira();
	}
}
/*

*/