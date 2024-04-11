#include<bits/stdc++.h>
using namespace std;
const int N=2010,M=100010,mod=998244353;
int n,m,l[N],r[N],a[M],b[M],p,k[2][M],an[M],ke[N],ci[M];
long long int ans;
int main(){
	for(int i=2;i<=100000;i++)a[i]=1;
	for(int i=2;i<=100000;i++){
		if(a[i]==1){
			b[++p]=i;
		}
		for(int o=1;o<=p&&i*b[o]<=100000;o++){
			a[i*b[o]]=0;
			if(i%b[o]==0){
				break;
			}
		}
	}
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(int io=1;io<=m;io++){
		int ok=0,sum=0;
		for(int i=1;i<=n;i++){
			int lj=(l[i]/io+1)*io,rj=r[i]/io*io;
			if(l[i]%io==0)lj=l[i];
			if(rj<l[i]||lj>r[i])break;
			sum+=lj;
			ke[i]=(rj-lj)/io;
			if(i==n)ok=1;
		}
		if(ok==1&&m>=sum){
		
		int nowm=m-sum,xx=0;
		k[0][0]=1;
		for(int i=1;i<=n;i++){
			xx^=1;
			for(int v=0;v<=nowm;v+=io){
				if(v/io<=ke[i])k[xx][v]=((v>=io?k[xx][v-io]:0)+k[xx^1][v])%mod;
				else k[xx][v]=(k[xx][v-io]+k[xx^1][v]-k[xx^1][v-io*ke[i]-io])%mod;
			}
		}
		for(int v=0;v<=nowm;v+=io){
			an[io]=(an[io]+k[xx][v])%mod;
			k[xx][v]=k[xx^1][v]=0;
		}
		
		}
		else{
			an[io]=0;
		}
		
	}
	ci[1]=-1;
	for(int i=1;i<=m;i++){
		for(int v=i*2;v<=m;v+=i){
			ci[v]-=ci[i];
		}
		ans-=an[i]*ci[i]%mod;
		ci[i]=0;
	}
	printf("%lld\n",(ans%mod+mod)%mod);
}