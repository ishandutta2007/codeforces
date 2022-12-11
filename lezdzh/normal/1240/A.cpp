#include<cstdio>
#include<algorithm>
using namespace std;

int p[200001],q[200001],w[200001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&p[i]);
		sort(p+1,p+n+1);
		int x,a,y,b;
		scanf("%d%d%d%d",&x,&a,&y,&b);
		for(int i=1;i<=n;i++)
			q[i]=0;
		for(int i=1;i*a<=n;i++)
			q[i*a]+=x;
		for(int i=1;i*b<=n;i++)
			q[i*b]+=y;
		long long k;
		scanf("%lld",&k);
		k*=100;
		int l=0,r=n+1;
		while(l!=r){
			int mid=l+r>>1;
			for(int i=1;i<=mid;i++)
				w[i]=q[i];
			sort(w+1,w+mid+1);
			long long ans=0;
			for(int i=mid;i;i--)
				ans+=1ll*w[i]*p[i-mid+n];
			if(ans>=k)r=mid;
			else l=mid+1;
		}
		printf("%d\n",l==n+1?-1:l);
	}
}