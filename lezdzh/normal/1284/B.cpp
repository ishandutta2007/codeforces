#include<cstdio>
#include<algorithm>
using namespace std;

int t,p[100001],q[100001];
int a[100001];
int main(){
	int n,w=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[0]);
		int ok=0;
		for(int j=1;j<=a[0];j++)
			scanf("%d",&a[j]);
		for(int j=1;j<a[0];j++)
			if(a[j+1]>a[j])ok=1;
		if(ok)w++;
		else{
			t++;
			q[t]=a[1];
			p[t]=a[a[0]];
		}
	}
	sort(p+1,p+t+1);
	long long ans=0;
	for(int i=1;i<=t;i++)
		ans+=lower_bound(p+1,p+t+1,q[i])-p-1;
	ans+=1ll*w*w+2ll*w*(n-w);
	printf("%lld\n",ans);
}