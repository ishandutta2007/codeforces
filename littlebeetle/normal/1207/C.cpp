#include<cstdio>
typedef long long ll;
const int N=200020;
int T,n,a,b,i,j,p[N];
ll f[N][2];
char s[N];
ll min(ll x,ll y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d%s",&n,&a,&b,s+1);
		n++;
		for(i=1;i<=n;i++)
			f[i][0]=f[i][1]=1ll<<60;
		f[1][0]=b;
		for(i=2;i<=n;i++){
			if(s[i-1]==48){
				f[i][1]=b*2+min(f[i-1][1]+a,f[i-1][0]+a*2);
				f[i][0]=b+min(f[i-1][0]+a,f[i-1][1]+a*2);
			}
			else
				f[i][1]=b*2+f[i-1][1]+a;
		}
		printf("%lld\n",f[n][0]);
	}
	//while(1);
}