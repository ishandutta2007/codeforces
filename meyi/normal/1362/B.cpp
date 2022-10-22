#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2051;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],cnt[maxn],n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		memset(cnt,0,sizeof cnt);
		scanf("%d",&n);
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i);
			++cnt[a[i]];
		}
		ri ans=-1;
		for(ri i=1;i<1025;++i){
			bool flag=true;
			for(ri j=1;j<1025;++j)flag&=(cnt[j]==cnt[i^j]);
			if(flag){
				ans=i;
				break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}