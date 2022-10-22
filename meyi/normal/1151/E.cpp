#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],n;
ll ans1,ans2;
signed main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),ans1+=1ll*a[i]*(n-a[i]+1);
	for(ri i=1;i<n;++i){
		ri x=a[i],y=a[i+1];
		if(x>y)swap(x,y);
		ans2+=1ll*x*(n-y+1);
	}
	printf("%lld",ans1-ans2);
	return 0;
}