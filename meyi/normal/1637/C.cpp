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
		if(n==3&&(a[2]&1)){puts("-1");continue;}
		if(all_of(a+2,a+n,[&](int x){return x==1;})){puts("-1");continue;}
		ri cnt=0;
		ll sum=0;
		for(ri i=2;i<n;++i)cnt+=a[i]&1,sum+=a[i];
		printf("%lld\n",cnt+sum>>1);
	}
	return 0;
}