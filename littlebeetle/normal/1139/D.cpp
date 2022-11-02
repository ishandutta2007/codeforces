#include<cstdio>
const int N=100002,M=1000000007;
typedef long long ll;
int m,a[N],p[N],i,j,k,x,y,z,cnt,d[N];
bool f[N];
ll inv[N],F[N],ans;
void init(){
	scanf("%d",&m);
	for(i=2;i<=m;i++){
		if(!f[i])a[k++]=i,p[i]=i;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<=m;j++){
			f[i*a[j]]=1;
			p[i*a[j]]=a[j];
		}
	}
	for(inv[1]=1,i=2;i<=m;i++)
		inv[i]=(M-M/i)*inv[M%i]%M;
}
void dfs(int i,int val,int sum){
	if(i>cnt){
		F[x*y]=(F[x*y]+(1+F[x])*(m/(x*val))%M*(sum%2?(M-1):1)%M*inv[m-m/x/y])%M;
		return;
	}
	dfs(i+1,val*d[i],sum+1);
	dfs(i+1,val,sum);
}
void work(){
	F[1]=1;
	for(x=1;x<=m;x++){
		F[x]=(F[x]+m/x*inv[m-m/x])%M;
		for(y=2;x*y<=m;y++){
			cnt=0;z=y;
			while(z!=1){
				if((z/p[z])%p[z])
					d[++cnt]=p[z];
				z/=p[z];
			}
			dfs(1,1,0);
		}
		ans=(ans+F[x])%M;
	}
	printf("%lld\n",ans*inv[m]%M);
}
int main(){
	init();
	work();
}