//The Hunting Party - Keys To The Kingdom
#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false)
#define ll __int128
#define mp make_pair
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
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
int n,a[N],b[N];
pair<double,int> c[N];
double cnt1[N];
int cnt[N];
int ansx,ansy,Ansx,Ansy;
double ans;
vector<int>G[N];
vector<int>ansg;
set<pa>S;
int lcm(int x,int y)
{
	return x/__gcd(x,y)*y;
}
void LYC_music()
{
	n=read();
	ansg.clear();
	set<pa>().swap(S);
	ans=0;
	for (int i=1;i<=200000;i++) S.insert({0,i}),cnt[i]=0;
	for (int i=1;i<=n;i++) 
	{
		a[i]=read(),b[i]=read();
		G[b[i]].push_back(i);
		cnt[a[i]]++;
	}
	int B=200000;
	for (int i=1;i<=21;i++)
	{
		double sum=0;
		int x=1,X=1;
		for (int j=1;j<=B;j++)
		{
			c[j]={1.0*(cnt[j]+cnt1[j]*1.0/i),j};
		}
		sort(c+1,c+B+1,greater<pair<double,int>>());
		vector<int>g;
		for (int j=1;j<=i;j++)
		{
			sum+=c[j].fi;
			g.push_back(c[j].se);
		}
//		cout<<"?"<<sum<<endl;
		if (sum>ans)
		{
			ans=sum;
			ansg.swap(g);
		}
		for (auto u:G[i])
		{
			cnt[a[u]]--;
			cnt1[a[u]]+=b[u];
		}
	}
	writeln(ansg.size());
	for (auto u:ansg) writesp(u);
	puts("");
}
signed main()
{
	int T=1;
	while (T--)
	{
		LYC_music();
	}
}
/*

*/