#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5,P=1e9+7;
int T,n,m,k,a[N],fact[N],invf[N],invp[N],ans;
int C(int x,int y){return x<y?0ll:1ll*fact[x]*invf[y]%P*invf[x-y]%P;}
void solve(){
	scanf("%d",&n);
	for(int i=0;i<=n;i++)scanf("%d",&a[i]);
	fact[0]=fact[1]=invf[0]=invf[1]=invp[1]=1;
	for(int i=2;i<N;i++)fact[i]=1ll*fact[i-1]*i%P,invp[i]=1ll*(P-P/i)*invp[P%i]%P,invf[i]=1ll*invf[i-1]*invp[i]%P;
	for(int i=0;i<=n;i++)ans=(ans+C(i+a[i],i+1))%P;
	printf("%d\n",ans);
}
int main(){
	T=1;//scanf("%d",&T);
	while(T--)solve();
	return 0;
}