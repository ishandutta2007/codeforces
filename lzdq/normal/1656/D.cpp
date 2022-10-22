#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
inline bool Check(ll n,ll k){
	if(k>=2e9) return 0;
	k=k*(k+1)/2;
	return k<=n;
}
ll Calc(ll n){
	if(n&1) return 2;
	if(n==(n&-n)) return -1;
	ll k=n;
	while(!(k&1)) k>>=1;
	if(Check(n,k)) return k;
	k=1ll<<__builtin_ffsll(n);
	if(Check(n,k)) return k;
	return -100;
}
int main(){
	ll n;
	int _; scanf("%d",&_);
	while(_--){
		scanf("%lld",&n);
		printf("%lld\n",Calc(n));
	}
	return 0;
}