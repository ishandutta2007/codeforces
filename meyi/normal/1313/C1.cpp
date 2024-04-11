#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=5e5+10;
int a[maxn],ans[maxn],m,n,st[maxn],tp,t_case;
ll ans1,ans2,l[maxn],r[maxn];
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	st[tp=1]=0;
	for(ri i=1;i<=n;++i){
		while(tp&&a[st[tp]]>=a[i])--tp;
		l[i]=l[st[tp]]+1ll*(i-st[tp])*a[i];
		st[++tp]=i;
	}
	st[tp=1]=n+1;
	for(ri i=n;i;--i){
		while(tp&&a[st[tp]]>=a[i])--tp;
		r[i]=r[st[tp]]+1ll*(st[tp]-i)*a[i];
		st[++tp]=i;
	}
	for(ri i=1;i<=n;++i)
		if(l[i]+r[i]-a[i]>ans1)
			ans1=l[i]+r[i]-a[i],ans2=i;
	for(ri i=ans2,tmp=a[ans2];i;--i){
		ckmin(tmp,a[i]);
		ans[i]=tmp;
	}
	for(ri i=ans2,tmp=a[ans2];i<=n;++i){
		ckmin(tmp,a[i]);
		ans[i]=tmp;
	}
	for(ri i=1;i<=n;++i)printf("%d ",ans[i]);
	return 0;
}