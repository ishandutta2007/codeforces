// LUOGU_RID: 90285068
#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=1.5e5+5,M=2.7e6+5,MOD=998244353;
constexpr int &reduce(int &x){(x>=MOD)&&(x-=MOD);return x;}
constexpr int reduce2(int x){(x>=MOD)&&(x-=MOD);return x;}
int n,k,c[M],t[M][2],ind=1,pw[N];
void insert(int a)
{
	int u=1;++c[u];
	for(int i=30;~--i;)
	{
		int x=a>>i&1;
		if(!t[u][x])t[u][x]=++ind;
		++c[u=t[u][x]];
	}
}
int dfs(int u1,int u2,int h)
{
	if(!u1||!u2)return pw[c[u1]+c[u2]]-1;
	if(!h)return reduce2(pw[c[u1]]+pw[c[u2]]-2);
	--h;
	if(u1==u2)
	{
		if(k>>h)return dfs(t[u1][0],t[u1][1],h);
		else return reduce2(dfs(t[u1][0],t[u1][0],h)+dfs(t[u1][1],t[u1][1],h));
	}
	if(k>>h&1)return (int)(((dfs(t[u1][0],t[u2][1],h)+1ll)*(dfs(t[u2][0],t[u1][1],h)+1ll)-1ll)%MOD);
	else return (int)((dfs(t[u1][0],t[u2][0],h)+dfs(t[u1][1],t[u2][1],h)+
	(pw[c[t[u1][0]]]-1ll)*(pw[c[t[u1][1]]]-1ll)+(pw[c[t[u2][0]]]-1ll)*(pw[c[t[u2][1]]]-1ll))%MOD);
}
int main()
{
	F(i,pw[0]=1,N)reduce(pw[i]=pw[i-1]<<1);
	read(n,k);++k;
	F(i,0,n)
	{
		int a;read(a);
		insert(a);
	}
	printf("%d\n",dfs(1,1,30));
	return 0;
}