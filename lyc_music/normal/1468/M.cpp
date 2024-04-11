//QwQcOrZ yyds!!!
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC target("avx")
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
#define N 200005
#define B 40
using namespace std;
inline char gc(){static char buf[100000],*p1=buf,*p2=buf;return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;}
#define gc getchar
inline ll read(){char c=gc();ll su=0,f=1;for (;c<'0'||c>'9';c=gc()) if (c=='-') f=-1;for (;c>='0'&&c<='9';c=gc()) su=su*10+c-'0';return su*f;}
inline void write(ll x){if (x<0){putchar('-');write(-x);return;}if (x>=10) write(x/10);putchar(x%10+'0');}
inline void writesp(ll x){write(x),putchar(' ');}
inline void writeln(ll x){write(x);putchar('\n');}
int b[N];
unordered_map<int,int>Mp1[N];
unordered_map<int,int>Mp;
int n;
vector<int>G[N];
int T;
int tot;
int ans;
signed main()
{
	T=read();
	while (T--)
	{
		n=read();ans=0;tot=0;
		for (int i=1;i<=n;i++)
		{
			int x=read();
			G[i].clear();
			for (int j=1;j<=x;j++) 
			{
				int y=read();
				if (Mp.count(y)) G[i].push_back(Mp[y]);
				else G[i].push_back((Mp[y]=++tot));
			}
		}
		Mp.clear();
		for (int i=1;i<=n;i++)
		{
			if (ans) break;
			if (G[i].size()>B)
			{
				for (auto u:G[i])
				{
					b[u]=1;
				}
				for (int j=1;j<=n;j++)
					if (i!=j)
					{
						int x=0;
						for (auto u:G[j])
						{
							if (b[u]) x++;
						}
						if (x>=2) 
						{
							ans=1;
							writesp(i),writeln(j);
							break;
						}
					}
				for (auto u:G[i])
				{
					b[u]=0;
				}
			} else
			{
				for (int ii=0;ii<G[i].size();ii++)
				{
					for (int jj=ii+1;jj<G[i].size();jj++)
					{
						int u=G[i][ii];
						int v=G[i][jj],t=0;
						if (u<v) swap(u,v),t=1;
						if (ans) break;
						if (Mp1[u].count(v))
						{
							writesp(Mp1[u][v]),writeln(i);
							ans=1;
							break;
						}
						Mp1[u][v]=i;
					}
				}
			}
		}
		if (!ans) puts("-1");
		for (int i=1;i<=tot;i++) Mp1[i].clear();
	}
}
/*

*/