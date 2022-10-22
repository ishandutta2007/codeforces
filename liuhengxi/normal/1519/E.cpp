#include<cstdio>
#include<algorithm>
#include<map>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e5+5;
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
long long gcd(long long a,long long b){return !b?a:gcd(b,a%b);}
map<pair<long long,long long>,int> mp;
struct line
{
	int next,to;
}e[2*N];
int n,m,hd[N],cnt,ans,ansu[N],ansv[N],dep[N];
bool vis[N];
inline void addline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
bool dfs(int u,int fa)
{
	int la=-1;
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)if(i>>1!=fa)
	{
		int v=e[i].to;
		if(vis[v])
		{
			if(dep[v]<dep[u])la=~la?(ansu[ans]=la,ansv[ans]=i>>1,++ans),-1:i>>1;
		}
		else
		{
			dep[v]=dep[u]+1;
			if(dfs(v,i>>1))la=~la?(ansu[ans]=la,ansv[ans]=i>>1,++ans),-1:i>>1;
		}
	}
	return ~la&&~fa?(ansu[ans]=la,ansv[ans]=fa,++ans),false:true;
}
int main()
{
	F(i,0,N)hd[i]=-1;
	read(m);
	F(i,0,m)
	{
		int u,v;
		long long a,b,c,d,num,den,g;read(a,b,c,d);
		num=(a+b)*d,den=b*c;
		g=gcd(num,den);num/=g,den/=g;
		if(!mp.count(make_pair(num,den)))mp[make_pair(num,den)]=n++;
		u=mp[make_pair(num,den)];
		num=a*d,den=b*(c+d);
		g=gcd(num,den);num/=g,den/=g;
		if(!mp.count(make_pair(num,den)))mp[make_pair(num,den)]=n++;
		v=mp[make_pair(num,den)];
		addline(u,v);addline(v,u);
	}
	F(i,0,n)if(!vis[i])dfs(i,-1);
	printf("%d\n",ans);
	F(i,0,ans)printf("%d %d\n",ansu[i]+1,ansv[i]+1);
	return 0;
}