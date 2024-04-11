#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=1e5+5,INF=0x3fffffff,mod=998244353;
int n,a[MAXN],k[MAXN];
int ans,sum;
void Upd(int u,int w){
	if(!u) return ;
	int p=a[u],nk=(p+w-1)/w;
	if(nk==k[u]) return ;
	sum=(sum-(k[u]-1ll)*u%mod+mod)%mod;
	k[u]=nk;
	sum=(sum+(k[u]-1ll)*u%mod)%mod;
	return Upd(u-1,p/k[u]);
}
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		ans=sum=0;
		for(int i=1; i<=n; i++){
			scanf("%d",a+i);
			k[i]=0;
			sum=(sum-i+mod)%mod;
			Upd(i,INF);
			ans=(ans+sum)%mod;
			//printf("%d sum %d\n",i,sum);
		}
		printf("%d\n",ans);
	}
	return 0;
}