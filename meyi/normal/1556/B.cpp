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
		ri cnt0=0,cnt1=0;
		for(ri i=1;i<=n;++i){
			scanf("%d",a+i),a[i]&=1;
			if(a[i])++cnt1;
			else ++cnt0;
		}
		if(cnt0!=n/2&&cnt1!=n/2)puts("-1");
		else{
			ri ans=0;
			if(cnt0>cnt1){
				for(ri i=n,j=n;i;--i)
					if(!a[i])
						ans+=abs(j-i),j-=2;
			}
			else if(cnt1>cnt0){
				for(ri i=n,j=n;i;--i)
					if(a[i])
						ans+=abs(j-i),j-=2;
			}
			else{
				ri ans1=0,ans2=0;
				for(ri i=n,j=n;i;--i)
					if(!a[i])
						ans1+=abs(j-i),j-=2;
				for(ri i=n,j=n;i;--i)
					if(a[i])
						ans2+=abs(j-i),j-=2;
				ans=min(ans1,ans2);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}