#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int k,n,t_case;
ll d[21],pw10[21];
bool vis[21];
int main(){
	pw10[0]=1;
	for(ri i=1;i<=18;++i)pw10[i]=pw10[i-1]*10;
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		memset(vis,0,sizeof vis);
		for(ri i=1,a;i<=n;++i)scanf("%d",&a),vis[a]=true;
		ll ans=0;
		ri i=0,lst=0;
		for(;i<=18&&k;++i){
			if(vis[i])lst=i;
			d[i]=min((ll)k,9*pw10[i-lst]);
			ans+=d[i]*pw10[lst];
			k-=d[i];
		}
		--i;
		printf("%lld\n",ans+(d[i]==9*pw10[i-lst]&&vis[i+1]?pw10[i+1]:pw10[lst]));
	}
	return 0;
}