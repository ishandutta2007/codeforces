#include<cstdio>
#include<algorithm>
using namespace std;

const int md=998244353;
int jc[200001],ny[200001];
int pw(int x,int y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%md)
		if(y&1)ans=1ll*ans*x%md;
	return ans;
}
int a[200001];
int main(){
	for(int i=jc[0]=1;i<=200000;i++)
		jc[i]=1ll*i*jc[i-1]%md;
	ny[200000]=pw(jc[200000],md-2);
	for(int i=200000;i;i--)
		ny[i-1]=1ll*i*ny[i]%md;
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,mx=-2e9,sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			mx=max(mx,a[i]);
		}
		for(int i=1;i<=n;i++)
			if(a[i]==mx)sum++;
		if(sum>=2){
			printf("%d\n",jc[n]);
		}
		else{
			sum=0;
			for(int i=1;i<=n;i++)
				if(a[i]==mx-1)sum++;
			int ans=jc[n];
			for(int i=n;i>sum;i--)
				ans=(ans-1ll*jc[n-1-sum]*ny[i-1-sum]%md*jc[i-1]%md+md)%md;
			printf("%d\n",ans);
		}
	}
}