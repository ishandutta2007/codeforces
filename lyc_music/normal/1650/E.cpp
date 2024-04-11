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
#define inf 3e9
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int n,d,a[N];
int ans;
int b[N];
void work(int x)
{
	int cnt=0;
	for (int i=1;i<=n;i++)
		if (i!=x) b[++cnt]=a[i];
	b[++cnt]=d;
	int p=inf;
	for (int i=1;i<=cnt;i++)
	{
		p=min(p,b[i]-b[i-1]-1);
	}
	multiset<int>S;
	for (int i=1;i<cnt;i++) S.insert(b[i]-b[i-1]-1);
	ans=max(ans,p);
	// cout<<"?"<<p<<endl;
	for (int i=1;i<cnt;i++)
	{
		if (b[i]-b[i-1]>=2)
		{
			S.erase(S.find(b[i]-b[i-1]-1));
			int x=b[i-1]+1,y=b[i]-1;
			int mid=(x+y)/2;
			S.insert(mid-b[i-1]-1);
			S.insert(b[i]-mid-1);
			ans=max(ans,(*S.begin()));
			// cout<<"?"<<b[i-1]<<" "<<mid<<" "<<b[i]<<" "<<(*S.begin())<<endl;
			S.erase(S.find(mid-b[i-1]-1));
			S.erase(S.find(b[i]-mid-1));
			S.insert(b[i]-b[i-1]-1);
		}
	}
}
void BellaKira()
{
	n=read(),d=read();
	a[0]=0;
	ans=0;
	for (int i=1;i<=n;i++) a[i]=read();
	
	int mn=inf;
	int x=0;
	for (int i=1;i<=n;i++)
		if (a[i]-a[i-1]-1<mn) mn=a[i]-a[i-1]-1,x=i;
	if (x) work(x);
	if (x-1) work(x-1);
	
	
	writeln(ans);
		
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