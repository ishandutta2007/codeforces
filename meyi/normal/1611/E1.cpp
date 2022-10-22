#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],dep[maxn],fdep[maxn],k,m,n,t_case;
vector<int>g[maxn];
void dfs(int p,int f){
	dep[p]=dep[f]+1;
	for(ri i:g[p])
		if(i!=f)
			dfs(i,p);
}
int main(){
	dep[0]=-1;
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		for(ri i=1;i<=n;++i)fdep[i]=INT_MAX,g[i].clear();
		queue<int>q;
		for(ri i=1;i<=k;++i)scanf("%d",a+i),fdep[a[i]]=0,q.push(a[i]);
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			g[x].push_back(y),g[y].push_back(x);
		}
		dfs(1,0);
		while(q.size()){
			ri p=q.front();q.pop();
			for(ri i:g[p])
				if(fdep[p]+1<fdep[i]){
					fdep[i]=fdep[p]+1;
					q.push(i);
				}
		}
		for(ri i=2;i<=n;++i)
			if(g[i].size()==1&&dep[i]<fdep[i]){
				puts("YES");
				goto skip;
			}
		puts("NO");
		skip:;
	}
	return 0;
}