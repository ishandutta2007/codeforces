#include<cstdio>
const int N=5002;
typedef long long ll;
int n,m,k,i,j,a[N];
ll f[N][N],s[N];
ll max(ll x,ll y){
	return x>y?x:y;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),s[i]=s[i-1]+a[i];
	for(i=1;i<=n;i++)
		for(j=1;j<=k;j++)
			if(i>=m)
				f[i][j]=max(f[i-1][j],f[i-m][j-1]+s[i]-s[i-m]);
	printf("%I64d",f[n][k]);
	return 0;
}