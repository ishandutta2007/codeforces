#include<cstdio>
#include<algorithm>
using namespace std;

int a[400001],c[400001];
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int w=0;
	for(int k=26;k;k--){
		for(int i=1;i<=n;i++)
			c[i]=a[i]&(1<<k)-1;
		sort(c+1,c+n+1);
		long long ans=0;
		for(int i=1;i<=n;i++){
			int l=(1<<k-1),r=(1<<k)-1;
			l=(l-c[i]+(1<<k))&(1<<k)-1;
			r=(r-c[i]+(1<<k))&(1<<k)-1;
			if(l<=r)ans+=upper_bound(c+1,c+n+1,r)-lower_bound(c+1,c+n+1,l);
			else ans+=n-(lower_bound(c+1,c+n+1,l)-upper_bound(c+1,c+n+1,r));
			if(l<=r?c[i]>=l&&c[i]<=r:c[i]>=l||c[i]<=r)ans--;
			//printf("%d %d %d %lld\n",c[i],l,r,ans);
		}
		//printf("%lld\n",ans);
		ans/=2;
		if(ans&1)w+=1<<k-1;
	}
	printf("%d\n",w);
}