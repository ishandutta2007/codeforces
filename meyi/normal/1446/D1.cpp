#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],ans,cnt[110],lst[maxn<<1],mx,mxx,n,val;
inline int calc(int k){
	memset(lst,-1,sizeof lst);
	lst[0+maxn]=0;
	ri ret=0,sum=0;
	for(ri i=1;i<=n;++i){
		if(a[i]==mx)++sum;
		if(a[i]==k)--sum;
		if(lst[sum+maxn]!=-1)ckmax(ret,i-lst[sum+maxn]);
		else lst[sum+maxn]=i;
	}
	return ret;
}
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		++cnt[a[i]];
		if(cnt[a[i]]>val)mx=a[i],mxx=0,val=cnt[a[i]];
		else if(a[i]!=mx&&cnt[a[i]]==val)mxx=a[i];
	}
	if(mxx)return printf("%d",n),0;
	for(ri i=1;i<101;++i)
		if(cnt[i]&&i!=mx)
			ckmax(ans,calc(i));
	printf("%d",ans);
	return 0;
}