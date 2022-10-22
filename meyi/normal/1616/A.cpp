#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=110;
int a[maxn],cnt[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			++cnt[abs(a[i])];
		}
		ri ans=0;
		for(ri i=0;i<=100;++i){
			ans+=min(cnt[i],2-!i);
			cnt[i]=0;
		}
		printf("%d\n",ans);
	}
	return 0;
}