#include<cstdio>
const int N=100002;
typedef long long ll;
int n,i,j,a[N];
ll f[N][5];
char s[N],p[5]={'#','h','a','r','d'};
ll min(ll x,ll y){
	return x<y?x:y;
}
int main(){
	f[0][1]=f[0][2]=f[0][3]=f[0][4]=1ll<<60;
	scanf("%d%s",&n,s+1);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		for(j=0;j<=4;j++)
			f[i][j]=f[i-1][j];
		for(j=0;j<=4;j++)
			if(s[i]==p[j]){
				f[i][j]=min(f[i-1][j],f[i-1][j-1]);
				f[i][j-1]=f[i-1][j-1]+a[i];
			}
	}
	printf("%I64d",min(f[n][0],min(f[n][1],min(f[n][2],f[n][3]))));
}