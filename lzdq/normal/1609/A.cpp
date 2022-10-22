#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=20;
int n,a[MAXN],b[MAXN],c[MAXN];
ll ans;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			b[i]=0;
			c[i]=a[i];
			while(!(c[i]&1)) c[i]>>=1,b[i]++;
		}
		ans=0;
		for(int i=1; i<=n; i++){
			int cnt=0;
			ll res=0;
			for(int j=1; j<=n; j++)
				if(i!=j) cnt+=b[j],res+=c[j];
			res+=(ll)(a[i])<<cnt;
			ans=max(ans,res);
		}
		printf("%lld\n",ans);
	}
	return 0;
}