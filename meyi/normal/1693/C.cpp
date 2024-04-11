#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int deg[maxn];
vector<int>to[maxn];
bool vis[maxn];
template<class T>
inline void dijkstra(T *dis,int siz,int st){
	clear(dis,siz,0x3f);
	dis[st]=0;
	typedef pair<int,int> pii;
	#define fi first
	#define se second
	priority_queue<pii>q;
	q.emplace(0,st);
	while(q.size()){
		ri p=q.top().se;q.pop();
		if(vis[p])continue;
		vis[p]=true;
		for(ri i:to[p]){
			if(dis[p]+deg[i]<dis[i]&&!vis[i]){
				dis[i]=dis[p]+deg[i];
				q.emplace(-dis[i],i);
			}
			--deg[i];
		}
	}
}
int f[maxn],m,n;
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		++deg[x],to[y].push_back(x);
	}
	dijkstra(f,n,n);
	printf("%d",f[1]);
	return 0;
}