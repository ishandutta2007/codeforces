#include<cstdio>
typedef long long ll;
ll n,m,g,T,u,v,id1,id2;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
ll Get(ll u,ll v){
	if(u==1)return (v-1)/(n/g);
	if(u==2)return (v-1)/(m/g);
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&T);
	g=gcd(n,m);
	while(T--){
		scanf("%I64d%I64d",&u,&v);
		id1=Get(u,v);
		scanf("%I64d%I64d",&u,&v);
		id2=Get(u,v);
		printf("%s\n",id1==id2?"YES":"NO");
	}
	//while(1);
	return 0;
}