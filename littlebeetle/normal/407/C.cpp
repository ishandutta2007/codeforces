#include<cstdio>
const int N=100002,K=103;
const int M=1000000007;
int n,m,i,j,k,l,r,p,inv[K];
int s[N][K],val[N];
void init(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",val+i);
	for(inv[1]=1,i=2;i<K;i++)
		inv[i]=1ll*(M-M/i)*inv[M%i]%M;	
}
void work(){
	while(m--){
		scanf("%d%d%d",&l,&r,&k);
		s[l][k]=(s[l][k]+1)%M;
		for(i=k,p=1;i>=0;i--){
			s[r+1][i]=(s[r+1][i]-p+M)%M;
			p=1ll*p*(r-l+k-i+1)%M*inv[k-i+1]%M;
		}
	}
	for(j=K-2;j>=0;j--)
		for(i=1;i<=n;i++)
			s[i][j]=(1ll*s[i][j]+s[i-1][j]+s[i][j+1])%M;
	for(i=1;i<=n;i++)
		printf("%d ",(s[i][0]+val[i])%M);
}
int main(){
	init();
	work();
	return 0;
}