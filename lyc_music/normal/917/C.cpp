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
pa b[505];
vector<int>P;
int c[505];
vector<pa>Q[1005];
int X,K,n,q;
int id[505];
int m;
vector<pa>To[1005];
struct matrix
{
	int n,m;
	int a[135][135];
}M[30];
matrix ans,C;
matrix mul(matrix x,matrix y)
{
	matrix res;
	res.n=x.n;
	res.m=y.m;
	for (int i=1;i<=res.n;i++)
		for (int j=1;j<=res.m;j++)
			res.a[i][j]=inf;
	for (int i=1;i<=res.n;i++)
		for (int j=1;j<=y.m;j++)
			for (int k=1;k<=x.m;k++)
				res.a[i][j]=min(res.a[i][j],x.a[i][k]+y.a[k][j]);
	return res;
}
void Pw(int x)
{
	for (int i=0;i<27;i++)
	{
		if ((x>>i)&1) ans=mul(ans,M[i]);
	}
}
void LYC_music()
{
	X=read(),K=read(),n=read(),q=read();
	for (int i=1;i<=K;i++) c[i]=read();
	for (int i=1;i<=q;i++)
	{
		b[i].fi=read(),b[i].se=read();
		for (int j=0;j<K;j++)
		{
			if (b[i].fi-j<=1) break;
			P.push_back(b[i].fi-j);
		}
	}
	sort(P.begin(),P.end());
	P.erase(unique(P.begin(),P.end()),P.end());
	for (int i=1;i<=q;i++)
	{
		for (int j=0;j<K;j++)
		{
			if (b[i].fi-j<=1) break;
			int k=lower_bound(P.begin(),P.end(),b[i].fi-j)-P.begin();
			Q[k].push_back(mp(j,b[i].se));
		}
	}
	vector<int>G;
	for (int i=1;i<(1<<(K));i++)
	{
		if (__builtin_popcount(i)==X)
		{
			G.push_back(i);
			id[i]=G.size();
		}
	}
	m=G.size();
	C.n=m;
	C.m=m;
	memset(C.a,0x3f,sizeof(C.a));
	for (auto u:G)
	{
		if (u%2==0)
		{
			C.a[id[u]][id[u/2]]=0;
			continue;
		}
		vector<int>g;
		int now=u;
		int p=0;
		for (int j=0;j<=K;j++)
		{
			int nowb=(now&1);
			now/=2;
//			cout<<"?"<<nowb<<"?"<<u<<endl;
			if (nowb==1)
			{
				if (!p) p=j;
				continue;
			}
			int x=u;
			x-=1;
			x+=(1<<j);
			x/=2;
//			cout<<"?? "<<u<<" "<<x<<" "<<j<<endl;
			C.a[id[u]][id[x]]=c[j];
			To[u].push_back({x,j});
		}
	}
	M[0]=C;
	for (int i=1;i<27;i++) M[i]=mul(M[i-1],M[i-1]);
	ans.n=1;
	ans.m=m;
	memset(ans.a,0x3f,sizeof(ans.a));
	ans.a[1][id[(1<<X)-1]]=0;
//	ans=mul(ans,C);
//		writeln(ans.a[1][id[(1<<X)-1]]);
//	return;
	int lst=1;
	for (int i=0;i<P.size();i++)
	{
		if (P[i]>n-X+1) break;
		Pw(P[i]-1-lst);
//		writeln(ans.a[1][id[(1<<X)-1]]);
//		cout<<"?"<<C.a[1][1]<<" "<<P[i]-1<<endl;
		matrix nowc=C;
		for (auto U:Q[i])
		{
			int u=U.fi,w=U.se;
			for (int j=1;j<=m;j++)
			{
				for (auto V:To[G[j-1]])
				{
					int v=V.fi,dis=V.se;
					if (((v>>(u))&1)&&((G[j-1]>>(u+1))%2==0))
					{
						nowc.a[j][id[v]]+=w;
					}
				}
			}
		}
		ans=mul(ans,nowc);
		lst=P[i];
//		writeln(ans.a[1][id[(1<<X)-1]]);
//		puts("");
	}
//	cout<<"?"<<lst<<" "<<n<<endl;
	Pw(n-lst-X+1);
	writeln(ans.a[1][id[(1<<X)-1]]);
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
2 8 85 25
492266845 33510072 886523743 473694882 423098690 347309510 536406077 916069301
68 -670378539
8 141902011
43 -84030444
19 -519169748
56 -187064805
14 -237674403
31 -544566859
76 58127796
64 -222971417
83 -712619543
20 -767112722
59 -831456183
13 489832592
15 -789976137
39 318003101
66 491222453
70 23439534
58 -185371556
69 -21442899
61 -735529104
60 77989991
63 -11663315
44 -295106551
54 -41933766
48 662973000
*/