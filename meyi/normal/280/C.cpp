#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int dep[maxn],n;
double ans;
void dfs(int p,int f){
	dep[p]=dep[f]+1;
	ans+=1.0/dep[p];
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=f)
			dfs(e[i].to,p);
}
int main(){
	scanf("%d",&n);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		addedge(x,y),addedge(y,x);
	}
	dfs(1,0);
	printf("%lf",ans);
	return 0;
}