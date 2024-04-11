#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri ans=INT_MAX;
		for(ri i=1;i<n;++i)
			for(ri j=i+1;j<=n;++j){
				ri cnt=0;
				for(ri k=1;k<=n;++k)
					if((a[j]-a[i])*(k-j)==(a[k]-a[j])*(j-i))
						++cnt;
				ckmin(ans,n-cnt);
			}
		printf("%d\n",ans==INT_MAX?0:ans);
	}
	return 0;
}