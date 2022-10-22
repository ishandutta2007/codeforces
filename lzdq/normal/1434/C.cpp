#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,c,d;
ll dmg(ll x){
	ll res=a*(x+1);
	res-=b*d*x*(x+1)/2;
	return res;
}
ll Calc(){
	if(a>b*c) return -1;
	if(a==b*c) return dmg(c/d);
	if(d>c) return a;
	return dmg(a/b/d);
}
int main(){
	//freopen("c.in","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		printf("%lld\n",Calc());
	}
	return 0;
}