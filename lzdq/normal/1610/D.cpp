#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,mod=1e9+7;
ll Fstpw(ll a,int b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}
int n,cnt[40];
ll ans;
int main(){
	scanf("%d",&n);
	memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		cnt[__builtin_ctz(x)]++;
	}
	ans=Fstpw(2,n)-1;
	int m=n-1;
	for(int i=0; i<=30; i++){
		m-=cnt[i];
		if(m<0) break;
		if(cnt[i]) ans=(ans-Fstpw(2,m)+mod)%mod;
	}
	printf("%lld\n",ans);
	return 0;
}