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
#define N 300005
using namespace std;
inline char gc(){static char buf[1000000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int c[N],dfn[N],rdfn[N],DFN;
vector<int>G[N],G1[N];
set<pa>S;
int c1[N];
int ans,n;
void ad(int x,int y)
{
	G[x].push_back(y);
}
void ad1(int x,int y)
{
	G1[x].push_back(y);
}
int query1(int x)
{
	int res=0;
	while (x)
	{
		res+=c1[x];
		x-=(x&(-x));
	}
	return res;
}
void dfs1(int k,int fa)
{
//	cout<<k<<" "<<fa<<endl;
	dfn[k]=++DFN;
	for (auto u:G1[k])
	{
		if (u==fa) continue;
		dfs1(u,k);
	}
	rdfn[k]=DFN;
}
void dfs(int k,int fa)
{
	vector<pa>g,g1;
	if (!S.empty())
	{
		auto it=(S.lower_bound({dfn[k],0}));
//		cout<<"?"<<k<<" "<<(it==S.end())<<" "<<dfn[k]<<endl;
		if (it==S.end()||dfn[(*it).se]>rdfn[k])
		{
			auto it1=S.lower_bound({dfn[k],0});
//			cout<<"!"<<(it1==S.begin())<<endl;
			if (it1!=S.begin())
			{
				it1--;
//				cout<<"?"<<rdfn[(*it1).se]<<endl;
				if (rdfn[(*it1).se]>=dfn[k])
				{
					pa u=(*it1);
					g.push_back(u);
//					cout<<"?ers"<<(*it1).se<<" "<<S.size()<<endl;
					S.erase(it1);
//					cout<<"?ers"<<(*it1).se<<" "<<S.size()<<endl;
				}
			}
			S.insert({dfn[k],k});
			g1.push_back({dfn[k],k});
		}
	} 
	else
	{
		S.insert({dfn[k],k});
		g1.push_back({dfn[k],k});
	}
//	cout<<"?"<<k<<" "<<S.size()<<endl;
	ans=max(ans,(int)S.size());
	for (auto u:G[k])
	{
		if (u==fa) continue;
		dfs(u,k);
	}
	for (auto u:g) S.insert(u);
	for (auto u:g1) S.erase(u);
}
void LYC_music()
{
	n=read();
	DFN=ans=0;
	for (int i=2;i<=n;i++)
	{
		int x=read();
		ad(x,i);
	}
	for (int i=2;i<=n;i++)
	{
		int x=read();
		ad1(x,i);
	}
	dfs1(1,0);
//	return;
	dfs(1,0);
	writeln(ans);
	for (int i=1;i<=n;i++) G[i].clear(),G1[i].clear();
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
1
8
1 2 2 3 5 6 5
1 2 2 3 2 5 7
*/