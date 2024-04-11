#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=3e5+10;
typedef pair<ll,int> pli;
#define fi first
#define se second
map<ll,int>cnt;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ll ans=0,sum=0;
		cnt.clear();
		++cnt[0];
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			if(i&1)sum+=a[i];
			else sum-=a[i];
			ans+=cnt[sum];
			++cnt[sum];
			if(i&1){
				while((--cnt.end())->fi>sum)cnt.erase(--cnt.end());
			}
			else{
				while(cnt.begin()->fi<sum)cnt.erase(cnt.begin());
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}