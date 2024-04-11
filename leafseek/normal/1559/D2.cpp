#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
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
#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
//aosidfhiasudyfinasudf
using namespace std;
const int MaxN=100000+5,Limit=300;
unsigned long long Temp[1568+5];
struct Connection_Disjoint_Set
{
	int fa[MaxN],siz[MaxN];
	int idx[MaxN];
	vector<int> vec[MaxN];
	unsigned long long Bitset[2000+5][1568+5];
	int Cnt;
	inline void Initalize(const register int len)
	{
		rep(i,1,len)
		{
			fa[i]=i,siz[i]=1;
			vec[i].push_back(1),vec[i].push_back(i);
		}
	}
	inline int getf(const register int u)
	{
		if(u!=fa[u])
			fa[u]=getf(fa[u]);
		return fa[u];
	}
	inline void Merge(const register int u,const register int v)
	{
		register int fu=getf(u),fv=getf(v);
		if(fu!=fv)
		{
			if(siz[fu]<siz[fv]) swap(fu,fv);
			fa[fv]=fu,siz[fu]+=siz[fv];
			if(idx[fu])
			{
				if(idx[fv])
				{
					for(register int i=0;i<=1552;i+=16)
					{
						Bitset[idx[fu]][i| 0]|=Bitset[idx[fv]][i| 0];
						Bitset[idx[fu]][i| 1]|=Bitset[idx[fv]][i| 1];
						Bitset[idx[fu]][i| 2]|=Bitset[idx[fv]][i| 2];
						Bitset[idx[fu]][i| 3]|=Bitset[idx[fv]][i| 3];
						Bitset[idx[fu]][i| 4]|=Bitset[idx[fv]][i| 4];
						Bitset[idx[fu]][i| 5]|=Bitset[idx[fv]][i| 5];
						Bitset[idx[fu]][i| 6]|=Bitset[idx[fv]][i| 6];
						Bitset[idx[fu]][i| 7]|=Bitset[idx[fv]][i| 7];
						Bitset[idx[fu]][i| 8]|=Bitset[idx[fv]][i| 8];
						Bitset[idx[fu]][i| 9]|=Bitset[idx[fv]][i| 9];
						Bitset[idx[fu]][i|10]|=Bitset[idx[fv]][i|10];
						Bitset[idx[fu]][i|11]|=Bitset[idx[fv]][i|11];
						Bitset[idx[fu]][i|12]|=Bitset[idx[fv]][i|12];
						Bitset[idx[fu]][i|13]|=Bitset[idx[fv]][i|13];
						Bitset[idx[fu]][i|14]|=Bitset[idx[fv]][i|14];
						Bitset[idx[fu]][i|15]|=Bitset[idx[fv]][i|15];
					}
				}
				else
				{
					rep(i,1,vec[fv][0])
						Bitset[idx[fu]][vec[fv][i]>>6]|=(1uLL<<(vec[fv][i]&63));
				}
			}
			else
			{
				rep(i,1,vec[fv][0])
					++vec[fu][0],vec[fu].push_back(vec[fv][i]);
				if(vec[fu][0]>=Limit)
				{
					idx[fu]=(++Cnt);
					rep(i,1,vec[fu][0])
						Bitset[idx[fu]][vec[fu][i]>>6]|=(1uLL<<(vec[fu][i]&63));
				}
			}
		}
	}
	inline bool Same(const register int u,const register int v)
		{return (getf(u)==getf(v));}
};
Connection_Disjoint_Set C1,C2;
queue<int> qu,qv;
inline int Log_2A(const register unsigned val)
{
	register int temp;
	asm volatile ("bsrl %1, %%eax":"=a"(temp):"m"(val));
	return temp;
}
inline int Log_2B(const register unsigned long long val)
{
	if(val&(-1u))
		return Log_2A(val);
	return Log_2A(val>>32)|32;
}
int Perm[MaxN],Rev[MaxN];
int main()
{
	ios::sync_with_stdio(false),cin.tie(NULL);
	srand(19260817);
	register int n,m1,m2;
	cin>>n>>m1>>m2;
	rep(i,1,n) Perm[i]=i;
	random_shuffle(Perm+1,Perm+n+1);
	random_shuffle(Perm+1,Perm+n+1);
	random_shuffle(Perm+1,Perm+n+1);
	random_shuffle(Perm+1,Perm+n+1);
	random_shuffle(Perm+1,Perm+n+1);
	rep(i,1,n) Rev[Perm[i]]=i;
	C1.Initalize(n);
	while(m1--)
	{
		register int u,v;
		cin>>u>>v,C1.Merge(Perm[u],Perm[v]);
	}
	C2.Initalize(n);
	while(m2--)
	{
		register int u,v;
		cin>>u>>v,C2.Merge(Perm[u],Perm[v]);
	}
	register int Sum=0;
	rep(u,1,n)
	{
		if(max(m1,m2)+Sum+1==n) break;
		const register int x=C1.getf(u);
		const register int y=C2.getf(u);
		if(C1.idx[x]&&C2.idx[y])
		{
			for(register int i=0;i<=1552;i+=16)
			{
				Temp[i| 0]=C1.Bitset[C1.idx[x]][i| 0]|C2.Bitset[C2.idx[y]][i| 0];
				Temp[i| 1]=C1.Bitset[C1.idx[x]][i| 1]|C2.Bitset[C2.idx[y]][i| 1];
				Temp[i| 2]=C1.Bitset[C1.idx[x]][i| 2]|C2.Bitset[C2.idx[y]][i| 2];
				Temp[i| 3]=C1.Bitset[C1.idx[x]][i| 3]|C2.Bitset[C2.idx[y]][i| 3];
				Temp[i| 4]=C1.Bitset[C1.idx[x]][i| 4]|C2.Bitset[C2.idx[y]][i| 4];
				Temp[i| 5]=C1.Bitset[C1.idx[x]][i| 5]|C2.Bitset[C2.idx[y]][i| 5];
				Temp[i| 6]=C1.Bitset[C1.idx[x]][i| 6]|C2.Bitset[C2.idx[y]][i| 6];
				Temp[i| 7]=C1.Bitset[C1.idx[x]][i| 7]|C2.Bitset[C2.idx[y]][i| 7];
				Temp[i| 8]=C1.Bitset[C1.idx[x]][i| 8]|C2.Bitset[C2.idx[y]][i| 8];
				Temp[i| 9]=C1.Bitset[C1.idx[x]][i| 9]|C2.Bitset[C2.idx[y]][i| 9];
				Temp[i|10]=C1.Bitset[C1.idx[x]][i|10]|C2.Bitset[C2.idx[y]][i|10];
				Temp[i|11]=C1.Bitset[C1.idx[x]][i|11]|C2.Bitset[C2.idx[y]][i|11];
				Temp[i|12]=C1.Bitset[C1.idx[x]][i|12]|C2.Bitset[C2.idx[y]][i|12];
				Temp[i|13]=C1.Bitset[C1.idx[x]][i|13]|C2.Bitset[C2.idx[y]][i|13];
				Temp[i|14]=C1.Bitset[C1.idx[x]][i|14]|C2.Bitset[C2.idx[y]][i|14];
				Temp[i|15]=C1.Bitset[C1.idx[x]][i|15]|C2.Bitset[C2.idx[y]][i|15];
			}
		}
		else if(C1.idx[x])
		{
			for(register int i=0;i<=1552;i+=16)
			{
				Temp[i| 0]=C1.Bitset[C1.idx[x]][i| 0];
				Temp[i| 1]=C1.Bitset[C1.idx[x]][i| 1];
				Temp[i| 2]=C1.Bitset[C1.idx[x]][i| 2];
				Temp[i| 3]=C1.Bitset[C1.idx[x]][i| 3];
				Temp[i| 4]=C1.Bitset[C1.idx[x]][i| 4];
				Temp[i| 5]=C1.Bitset[C1.idx[x]][i| 5];
				Temp[i| 6]=C1.Bitset[C1.idx[x]][i| 6];
				Temp[i| 7]=C1.Bitset[C1.idx[x]][i| 7];
				Temp[i| 8]=C1.Bitset[C1.idx[x]][i| 8];
				Temp[i| 9]=C1.Bitset[C1.idx[x]][i| 9];
				Temp[i|10]=C1.Bitset[C1.idx[x]][i|10];
				Temp[i|11]=C1.Bitset[C1.idx[x]][i|11];
				Temp[i|12]=C1.Bitset[C1.idx[x]][i|12];
				Temp[i|13]=C1.Bitset[C1.idx[x]][i|13];
				Temp[i|14]=C1.Bitset[C1.idx[x]][i|14];
				Temp[i|15]=C1.Bitset[C1.idx[x]][i|15];
			}
			rep(i,1,C2.vec[y][0])
				Temp[C2.vec[y][i]>>6]|=(1uLL<<(C2.vec[y][i]&63));
		}
		else if(C2.idx[y])
		{
			for(register int i=0;i<=1552;i+=16)
			{
				Temp[i| 0]=C2.Bitset[C2.idx[y]][i| 0];
				Temp[i| 1]=C2.Bitset[C2.idx[y]][i| 1];
				Temp[i| 2]=C2.Bitset[C2.idx[y]][i| 2];
				Temp[i| 3]=C2.Bitset[C2.idx[y]][i| 3];
				Temp[i| 4]=C2.Bitset[C2.idx[y]][i| 4];
				Temp[i| 5]=C2.Bitset[C2.idx[y]][i| 5];
				Temp[i| 6]=C2.Bitset[C2.idx[y]][i| 6];
				Temp[i| 7]=C2.Bitset[C2.idx[y]][i| 7];
				Temp[i| 8]=C2.Bitset[C2.idx[y]][i| 8];
				Temp[i| 9]=C2.Bitset[C2.idx[y]][i| 9];
				Temp[i|10]=C2.Bitset[C2.idx[y]][i|10];
				Temp[i|11]=C2.Bitset[C2.idx[y]][i|11];
				Temp[i|12]=C2.Bitset[C2.idx[y]][i|12];
				Temp[i|13]=C2.Bitset[C2.idx[y]][i|13];
				Temp[i|14]=C2.Bitset[C2.idx[y]][i|14];
				Temp[i|15]=C2.Bitset[C2.idx[y]][i|15];
			}
			rep(i,1,C1.vec[x][0])
				Temp[C1.vec[x][i]>>6]|=(1uLL<<(C1.vec[x][i]&63));
		}
		else
		{
			for(register int i=0;i<=1552;i+=16)
			{
				Temp[i| 0]=Temp[i| 1]=Temp[i| 2]=Temp[i| 3]=0;
				Temp[i| 4]=Temp[i| 5]=Temp[i| 6]=Temp[i| 7]=0;
				Temp[i| 8]=Temp[i| 9]=Temp[i|10]=Temp[i|11]=0;
				Temp[i|12]=Temp[i|13]=Temp[i|14]=Temp[i|15]=0;
			}
				
			rep(i,1,C1.vec[x][0])
				Temp[C1.vec[x][i]>>6]|=(1uLL<<(C1.vec[x][i]&63));
			rep(i,1,C2.vec[y][0])
				Temp[C2.vec[y][i]>>6]|=(1uLL<<(C2.vec[y][i]&63));
		}
		rep(i,0,1567)
		{
			Temp[i]=~Temp[i];
			register int v;
			while(Temp[i])
			{
				v=(i<<6)|Log_2B(Temp[i]&-Temp[i]);
				Temp[i]-=(Temp[i]&-Temp[i]);
				if(1<=v&&v<=n&&!C1.Same(u,v)&&!C2.Same(u,v))
				{
					++Sum,qu.push(Rev[u]),qv.push(Rev[v]);
					C1.Merge(u,v),C2.Merge(u,v);
				}
			}
		}
	}
	cout<<Sum<<endl;
	rep(i,1,Sum)
	{
		cout<<qu.front()<<' ',qu.pop();
		cout<<qv.front()<<' ',qv.pop();
		cout<<'\n';
	}
	return 0;
}