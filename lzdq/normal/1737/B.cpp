#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
ll Calc(ll x){
	if(x==0) return 0;
	ll y=sqrt(x);
	ll res=(y-1)*3+1;
	if(y*y+y<=x) res++;
	if(y*y+y*2<=x) res++;
	return res;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		ll x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",Calc(y)-Calc(x-1));
	}
	return 0;
}