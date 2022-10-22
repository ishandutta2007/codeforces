#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,t_case;
ll sum;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%lld",&n,&sum);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri ans1=0,ans2=-1;
		for(ri i=1,j=1;i<=n;++i){
			sum+=a[i];
			while(j<=i&&sum<0)sum-=a[j++];
			if(i-j+1>ans2-ans1+1)ans1=j,ans2=i;
		}
		if(ans2-ans1+1<1)puts("-1");
		else printf("%d %d\n",ans1,ans2);
	}
	return 0;
}