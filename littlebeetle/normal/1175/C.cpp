#include<cstdio>
#include<algorithm>
using namespace std;
const int N=200002,Inf=1e9+1;
int T,n,k,i,a[N],l,r,mid,u,v;
bool check(int x){
	for(i=1;i+k<=n;i++)
		if(a[i+k]-a[i]<=x*2){
			if(x<u)
				u=x,v=a[i+k]+a[i]>>1;
			return 1;
		}
	return 0;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		sort(a+1,a+n+1);
		u=v=1<<30;
		l=0;r=Inf;
		while(l<=r){
			mid=l+r>>1;
			if(check(mid))
				r=mid-1;
			else
				l=mid+1;
		}
		printf("%d\n",v);
	}
	//while(1);
}