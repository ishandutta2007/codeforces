#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,a[MAXN];
ll ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=0;
		bool ok=1;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			if(i>1&&i<n){
				ans+=a[i]+1>>1;
				if(a[i]>=2) ok=0;
			}
		}
		if(ok||n==3&&a[2]&1) ans=-1;
		printf("%lld\n",ans);
	}
	return 0;
}