#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int deg[maxn],n,t_case;
vector<int>g[maxn];
inline int toposort(){
	ri cnt=0,now=0,ret=0;
	priority_queue<int,vector<int>,greater<int> >q[2];
	for(ri i=1;i<=n;++i){
		sort(g[i].begin(),g[i].end());
		if(!deg[i])q[now].push(i);
	}
	while(q[0].size()||q[1].size()){
		++ret;
		while(q[now].size()){
			ri p=q[now].top();q[now].pop();
			++cnt;
			for(auto i:g[p])
				if(!--deg[i]){
					if(i<p)q[now^1].push(i);
					else q[now].push(i);
				}
		}
		now^=1;
	}
	return cnt<n?-1:ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)g[i].clear();
		for(ri i=1,y;i<=n;++i){
			scanf("%d",deg+i);
			for(ri j=1;j<=deg[i];++j)scanf("%d",&y),g[y].push_back(i);
		}
		printf("%d\n",toposort());
	}
	return 0;
}