#include<cstdio>
const int N=71,M=1000000007,K=100005;
int a[N],p[N],i,j,k;
int n,x,s[N],fac[K],inv[K];
int u[1<<19],v[1<<19],s1,s2;
bool f[N];
void pre(){
	for(i=2;i<N;i++){
		if(!f[i])p[i]=1<<k,a[k++]=i;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<N;j++){
			f[i*a[j]]=1;
			p[i*a[j]]=p[i]^(1<<j);
		}
	}
	for(fac[0]=1,i=1;i<K;i++)
		fac[i]=1ll*i*fac[i-1]%M;
	for(inv[1]=1,i=2;i<K;i++)
		inv[i]=1ll*(M-M/i)*inv[M%i]%M;
	for(inv[0]=1,i=1;i<K;i++)
		inv[i]=1ll*inv[i]*inv[i-1]%M;
}
int C(int n,int m){
	return 1ll*fac[n]*inv[m]%M*inv[n-m]%M;
}
void work(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&x);
		s[x]++;
	}
	u[0]=1;
	for(k=1;k<N;k++){
		s1=s2=0;
		for(i=0;i<=s[k];i++){
			if(i%2==0)
				s1=(s1+C(s[k],i))%M;
			else
				s2=(s2+C(s[k],i))%M;
		}
		for(i=0;i<(1<<19);i++){
			v[i]=(v[i]+1ll*u[i]*s1)%M;
			v[i^p[k]]=(v[i^p[k]]+1ll*u[i]*s2)%M;
		}
		for(i=0;i<(1<<19);i++){
			u[i]=v[i];
			v[i]=0;
		}
	}
	printf("%d",(u[0]+M-1)%M);
	//while(1);
}
int main(){
	pre();
	work();
}