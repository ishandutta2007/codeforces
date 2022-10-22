#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct edge{
	int v,to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to,int v=1){
	e[++len]={v,to,hd[fr]};
	hd[fr]=len;
}
int d[31];
inline void insert(int k){
	for(ri i=30;~i;--i)
		if(k&(1<<i)){
			if(!d[i]){
				d[i]=k;
				return;
			}
			else k^=d[i];
		}
}
inline int getmn(int k){
	for(ri i=30;~i;--i)ckmin(k,k^d[i]);
	return k;
}
bool cur[maxn],vis[maxn];
int val[maxn];
void dfs(int p,int xsum){
	cur[p]=vis[p]=true;
	val[p]=xsum;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to])dfs(e[i].to,xsum^e[i].v);
		else if(cur[e[i].to])insert(xsum^e[i].v^val[e[i].to]);
	cur[p]=false;
}
int m,n;
signed main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		addedge(x,y,z),addedge(y,x,z);
	}
	dfs(1,0);
	printf("%d",getmn(val[n]));
	return 0;
}