#include<cstdio>
const int N=100002;
typedef long long ll;
int n,i,j;
ll a[N][2],f[N][2];
ll max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	scanf("%d",&n);
	for(j=0;j<2;j++)
		for(i=1;i<=n;i++)
			scanf("%I64d",a[i]+j);
	for(i=1;i<=n;i++)
		for(j=0;j<2;j++)
			f[i][j]=max(f[i-1][j^1]+a[i][j],f[i-1][j]);
	printf("%I64d",max(f[n][0],f[n][1]));
}