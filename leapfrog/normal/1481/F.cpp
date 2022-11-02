//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005;int n,K,rr[N],idt,rrt,vs[N],rs[N],dg[N];
bitset<N>dp[5266];vector<int>v[N],cn[N],id[N],e[N],vi;
inline void pull(int nw,int vl)
{
	if(nw==0) return;else if(dp[nw-1][vl]) pull(nw-1,vl);
	else rr[++rrt]=nw,pull(nw-1,vl-vi[nw-1]);
}
inline void dfs(int x,int d) {v[d].push_back(x);for(auto y:e[x]) dfs(y,d+1),dg[x]++,dg[y]++;}
int main()
{
	read(n,K),dp[0][0]=1;int mxd=0;for(int i=2,x;i<=n;i++) read(x),e[x].push_back(i);//dep 
	dfs(1,1);for(int i=1;i<=n;i++) if(!v[i].empty()) cn[v[i].size()].push_back(i),mxd=i;//
	for(int i=1;i<=n;i++) if(!cn[i].empty())//
	{
		int cnt=cn[i].size(),gg=0,nw=1;
		for(;gg<cnt;gg+=nw,nw<<=1)
		{
			++idt,vi.push_back(i*min(nw,cnt-gg));// idt  dep
			for(int j=gg;j<cnt&&j<gg+nw;j++) id[idt].push_back(cn[i][j]);
		}
	}
	for(int i=1;i<=idt;i++) dp[i]=dp[i-1]|(dp[i-1]<<vi[i-1]);
	int wh=0;for(int i=K;i>=0;i--) if(dp[idt][i]) {wh=i;break;}
	pull(idt,wh);for(int i=1;i<=rrt;i++) for(auto x:id[rr[i]]) vs[x]=1;
	if(wh==K)
	{
		printf("%d\n",mxd);
		for(int i=1;i<=n;i++) if(vs[i]) for(auto w:v[i]) rs[w]=1;
		for(int i=1;i<=n;i++) putchar('b'-rs[i]);
		return putchar('\n'),0;
	}else printf("%d\n",mxd+1);
	int fg=1,x=K,y=n-K;for(int i=1;i<=n;i++)
	{
		sort(v[i].begin(),v[i].end(),[](int a,int b){return dg[a]>dg[b];});
		x<y?swap(x,y),fg^=1:0;for(size_t j=0;j<v[i].size();j++)
			rs[v[i][j]]=fg,x--,(!x?swap(x,y),fg^=1:0);
	}
	for(int i=1;i<=n;i++) putchar('b'-rs[i]);
	return putchar('\n'),0;
}