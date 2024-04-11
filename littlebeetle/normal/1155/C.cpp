#include<cstdio>
const int N=300002;
typedef long long ll;
int n,m,i;
ll x[N],p[N],g;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%I64d",x+i);
	for(i=1;i<=m;i++)
		scanf("%I64d",p+i);
	g=x[2]-x[1];
	for(i=2;i<n;i++)
		g=gcd(g,x[i+1]-x[i]);
	for(i=1;i<=m;i++)
		if(g%p[i]==0){
			printf("YES\n%I64d %d",x[1],i);
			return 0;
		}
	printf("NO");
}