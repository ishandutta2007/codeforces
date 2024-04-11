#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
const ll INF=1ll<<60;
int n,a[MAXN],b,c;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		b=c=0;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			a[i]&=1;
			if(a[i]) c++;
			else b++;
		}
		if(min(b,c)!=n/2){
			puts("-1");
			continue;
		}
		ll ans=INF,sum=0;
		if(b==n/2){
			for(int i=1,j=2; i<=n; i++)
				if(!a[i]) sum+=abs(i-j),j+=2;
			ans=min(ans,sum);
		}
		sum=0;
		if(c==n/2){
			for(int i=1,j=2; i<=n; i++)
				if(a[i]) sum+=abs(i-j),j+=2;
			ans=min(ans,sum);
		}
		printf("%lld\n",ans);
	}
	return 0;
}