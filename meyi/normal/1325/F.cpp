#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
vector<int>ans,cur;
int dep[maxn],k;
bool vis[maxn];
void dfs(int p){
	cur.push_back(p);
	dep[p]=cur.size();
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!dep[e[i].to])dfs(e[i].to);
		else if(dep[p]-dep[e[i].to]+1>=k){
			printf("2\n%d\n",dep[p]-dep[e[i].to]+1);
			while(cur.back()!=e[i].to)printf("%d ",cur.back()),cur.pop_back();
			printf("%d",e[i].to);
			exit(0);
		}
	if(!vis[p]){
		ans.push_back(p);
		vis[p]=true;
		for(ri i=hd[p];i;i=e[i].nxt)vis[e[i].to]=true;
	}
	cur.pop_back();
}
int m,n;
signed main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	k=ceil(sqrt(n));
	dfs(1);
	puts("1");
	for(ri i=0;i<k;++i)printf("%d ",ans[i]);
	return 0;
}