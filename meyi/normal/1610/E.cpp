#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
int a[maxn],m,n,t_case;
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		ri ans=0;
		for(ri i=1;i<=n;++i)
			if(a[i]>a[i-1]){
				ri cnt=1,pos=i,tmp=0;
				while(1){
					ri nxt=max(pos+1,lower_bound(a+1,a+n+1,a[pos]+tmp)-a);
					if(nxt>n)break;
					++cnt;
					pos=nxt;
					tmp=a[pos]-a[i];
				}
				ckmax(ans,cnt);
			}
		printf("%d\n",n-ans);
	}
	return 0;
}