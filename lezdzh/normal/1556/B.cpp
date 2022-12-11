#include<cstdio>
#include<algorithm>

using namespace std;

int a[100001];
int main(){
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		int n,sum=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum+=a[i]%2;
		}
		if(sum!=n/2&&sum!=(n+1)/2)printf("-1\n");
		else{
			long long ans=~0ull>>1;
			if(sum==n/2){
				int o=0;
				long long cur=0;
				for(int i=1;i<=n;i++)
					if(a[i]%2){
						o++;
						cur+=abs(i-o*2);
					}
				ans=min(ans,cur);
			}
			if(sum==(n+1)/2){
				int o=0;
				long long cur=0;
				for(int i=1;i<=n;i++)
					if(a[i]%2){
						o++;
						cur+=abs(i-o*2+1);
					}
				ans=min(ans,cur);
			}
			printf("%lld\n",ans);
		}
	}
}