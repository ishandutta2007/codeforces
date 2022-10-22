#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=4e5+10;
struct edge{
	int to,nxt;
}e[maxn<<1];
int deg[maxn],hd[maxn],len;
inline void addedge(int fr,int to){
	++deg[to];
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int a[maxn],ans[maxn],k,n,t_case;
queue<int>q[2];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		for(ri i=1;i<=n;++i)ans[i]=deg[i]=hd[i]=0;
		len=0;
		for(ri i=1,x,y;i<n;++i){
			scanf("%d%d",&x,&y);
			addedge(x,y),addedge(y,x);
		}
		for(ri i:{0,1})while(q[i].size())q[i].pop();
		for(ri i=1;i<=n;++i)
			if(deg[i]==1)
				q[0].push(i);
		ri cnt=0,dep=1;
		for(ri i=0;cnt<n-2;++dep,i^=1)
			while(q[i].size()){
				ri p=q[i].front();q[i].pop();
				ans[p]=dep,++cnt;
				for(ri j=hd[p];j;j=e[j].nxt){
					--deg[e[j].to];
					if(deg[e[j].to]==1)q[i^1].push(e[j].to);
				}
			}
		ri sum=0;
		for(ri i=1;i<=n;++i){
			if(!ans[i])ans[i]=dep;
			sum+=(ans[i]>k);
		}
		printf("%d\n",sum);
	}
	return 0;
}