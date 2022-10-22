#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],bl,m,n,t_case;
ll ans,cnt[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			b[i]=a[i];
		}
		sort(b+1,b+n+1);
		bl=unique(b+1,b+n+1)-b-1;
		for(ri i=1;i<=n;++i){
			a[i]=lower_bound(b+1,b+bl+1,a[i])-b;
			ans+=(n-i+1)*cnt[a[i]];
			cnt[a[i]]+=i;
		}
		printf("%lld\n",ans);
		ans=0;
		for(ri i=1;i<=n;++i)cnt[a[i]]=0;
	}
	return 0;
}