#include<cstdio>
const int N=100002;
typedef long long ll;
ll n,m,k,i,a[N];
ll min(ll x,ll y){
	return x<y?x:y;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&m,&k);
	if(n%2==0){
		printf("%d",0);
		return 0;
	}
	k=k*(m/((n+1)/2));
	for(i=1;i<=n;i++)
	scanf("%I64d",a+i);
	for(i=1;i<=n;i+=2)
	k=min(k,a[i]);
	printf("%I64d",k);
}