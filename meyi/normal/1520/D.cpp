#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=4e5+10;
int a,cnt[maxn],m,n,t_case;
ll ans;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ans=0;
		memset(cnt,0,sizeof cnt);
		for(ri i=1;i<=n;++i){
			scanf("%d",&a);
			ans+=cnt[a-i+n];
			++cnt[a-i+n];
		}
		printf("%lld\n",ans);
	}
	return 0;
}