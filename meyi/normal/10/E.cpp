#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=410;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],ans=INT_MAX,n;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=n;++i)
		for(ri j=i+1;j<=n;++j){
			ri cnt1=1,cnt2=0,m=a[i]-1;
			for(ri k=i+1;k<=j;++k)cnt1+=m/a[k],m%=a[k];
			m=a[i]-1-m+a[j];
			ri sum=m;
			for(ri k=1;k<=n;++k)cnt2+=m/a[k],m%=a[k];
			if(cnt2>cnt1)ckmin(ans,sum);
		}
	printf("%d",ans==INT_MAX?-1:ans);
	return 0;
}