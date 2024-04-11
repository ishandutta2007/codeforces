#include<cstdio>
typedef long long ll;
inline ll minn(ll a,ll b){
	if(a<b) return a;
	return b;
}
ll a,b,c;
ll ans1,ans2;
int main(){
	scanf("%I64d%I64d%I64d",&a,&b,&c);
	ans1=(a+b)/c;
	ll x=a/c,y=b/c;
	if(x+y!=ans1){
		ans2=1ll<<62;
		if((x+1)*c-a<=b) ans2=(x+1)*c-a;
		if((y+1)*c-b<=a) ans2=minn(ans2,(y+1)*c-b);
	}
	
	printf("%I64d %I64d\n",ans1,ans2);
	return 0;
}