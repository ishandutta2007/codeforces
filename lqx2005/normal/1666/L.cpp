#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef unsigned un;
typedef std::pair<int,int> pii;
typedef std::pair<ll,ll> pll;
ll read()
{
	ll f=1,x=0;int c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+(c-'0'),c=getchar();
	return f*x;
}
ll max(ll a,ll b){return a>b?a:b;}
ll min(ll a,ll b){return a<b?a:b;}
ll abs(ll x){return x>0?x:-x;}
template<typename T> inline bool umin(T& a,T t){if(t<a)return a=t,1;return 0;}
template<typename T> inline bool umax(T& a,T t){if(t>a)return a=t,1;return 0;}
/**********/
const int MAXN = 800011;
std::vector<int>g[MAXN];
int from[MAXN],pre[MAXN];
int Q[MAXN];
int main()
{
	int n=read(),m=read(),s=read();
	for(int i=1;i<=m;++i){int u=read(),v=read();g[u].emplace_back(v);}
	int h=0,t=0;
	for(auto v:g[s])
		pre[v]=s,from[v]=v,Q[t++]=v;
	while(h<t)
	{
		int u=Q[h++];
		for(auto v:g[u])
			if(v!=pre[u]&&v!=s)
			{
				if(from[v]&&from[v]!=from[u])
				{
					puts("Possible");
					int x=u,y=v;
					std::vector<int>P1,P2;
					P1.emplace_back(y);
					while(x!=s)P1.emplace_back(x),x=pre[x];
					P1.emplace_back(s);
					while(y!=s)P2.emplace_back(y),y=pre[y];
					P2.emplace_back(s);
					std::reverse(P1.begin(),P1.end()),std::reverse(P2.begin(),P2.end());
					printf("%d\n",int(P1.size()));
					for(auto x:P1)printf("%d ",x);
					puts("");
					printf("%d\n",int(P2.size()));
					for(auto x:P2)printf("%d ",x);
					puts("");
					return 0;
				}
				if(!from[v])from[v]=from[u],pre[v]=u,Q[t++]=v;
			}
	}
	puts("Impossible");
	return 0;
}