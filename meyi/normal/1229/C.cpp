#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll ans;
int m,n,out[maxn],q;
vector<int>in[maxn];
inline ll calc(int k){return 1ll*in[k].size()*out[k];}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		in[x].push_back(y),++out[y];
	}
	for(ri i=1;i<=n;++i)ans+=calc(i);
	printf("%lld\n",ans);
	scanf("%d",&q);
	while(q--){
		ri x;
		scanf("%d",&x);
		ans-=calc(x);
		for(ri i:in[x])ans-=calc(i),--out[i],in[i].push_back(x),ans+=calc(i);
		out[x]+=in[x].size(),in[x].clear();
		printf("%lld\n",ans);
	}
	return 0;
}