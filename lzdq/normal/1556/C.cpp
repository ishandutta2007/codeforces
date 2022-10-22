#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
ull ans;
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	for(int i=1; i<n; i++){
		if(i&1) ans+=min(a[i],a[i+1]);
		ll s1=0,s2=0;
		for(int j=i+2; j<=n; j++){
			if(j-1&1) s2+=a[j-1];
			else if(s2<=a[j-1]) s1+=a[j-1]-s2,s2=0;
			else s2-=a[j-1];
			if((i&1)&&!(j&1)) ans+=max(0ll,min(a[i]-s1,a[j]-s2)+1);
			//printf("j %d ans %lld\n",j,ans);
		}
		//printf("i %d ans %lld\n",i,ans);
	}
	printf("%llu\n",ans);
	return 0;
}