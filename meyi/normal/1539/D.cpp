#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct node{
	ll a,b;
	inline bool operator<(const node &k)const{
		return b<k.b;
	}
}g[maxn];
ll ans,cnt;
int m,n,t_case;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld%lld",&g[i].a,&g[i].b);
	sort(g+1,g+n+1);
	for(ri l=1,r=n;l<=r;){
		if(cnt>=g[r].b){
			ans+=g[r].a;
			cnt+=g[r].a;
			--r;
			continue;
		}
		if(cnt>=g[l].b){
			ans+=g[l].a;
			cnt+=g[l].a;
			++l;
			continue;
		}
		if(g[l].b-cnt<g[r].a){
			ans+=(g[l].b-cnt)*2;
			g[r].a-=g[l].b-cnt;
			cnt=g[l].b;
			continue;
		}
		ans+=g[r].a*2;
		cnt+=g[r].a;
		--r;
	}
	printf("%lld",ans);
	return 0;
}