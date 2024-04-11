#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int a[maxn],b[maxn],c[maxn],d[maxn],m,n,t_case;
ll suma[maxn],sumb[maxn];
inline bool check(int k){
	for(ri i=1;i<=n;++i)c[i]=a[i],d[i]=b[i];
	for(ri i=1;i<=k;++i)c[n+i]=100,d[n+i]=0;
	sort(c+1,c+n+k+1),sort(d+1,d+n+k+1);
	for(ri i=1;i<=n+k;++i)suma[i]=suma[i-1]+c[i],sumb[i]=sumb[i-1]+d[i];
	return suma[n+k]-suma[(n+k)/4]>=sumb[n+k]-sumb[(n+k)/4];
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i);
		for(ri i=1;i<=n;++i)scanf("%d",b+i);
		ri l=0,r=n*2,ret=0;
		while(l<=r){
			ri mid=l+r>>1;
			if(check(mid))ret=mid,r=mid-1;
			else l=mid+1;
		}
		printf("%d\n",ret);
	}
}