#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int dis[maxn];
vector<int>e[maxn];
int dfs(int p,int f,int d){
	ri a=0,b=0;
	for(ri i:e[p])
		if(i!=f){
			ri c=dfs(i,p,d+1)+1;
			if(c>a)b=a,a=c;
			else ckmax(b,c);
		}
	if(b+d)ckmax(dis[b+d-1],(a+b+1)>>1);
	return a;
}
int n,t_case;
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)dis[i]=0,vector<int>().swap(e[i]);
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			e[x].push_back(y),e[y].push_back(x);
		}
		ri lim=dfs(1,0,0);
		for(ri i=n-2;~i;--i)ckmax(dis[i],dis[i+1]);
		ri ans=1;
		for(ri i=1;i<=n;++i){
			while(dis[ans]+i>ans)++ans;
			printf("%d%c",min(ans,lim)," \n"[i==n]);
		}
	}
	return 0;
}