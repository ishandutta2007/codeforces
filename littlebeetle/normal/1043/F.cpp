#include<cstdio>
typedef long long ll;
const int N=300002,M=1000000007;
int n,i,j,k,a,s[N];
ll fac[N],inv[N],f[N];
void pre(){
	for(fac[0]=1,i=1;i<N;i++)
		fac[i]=i*fac[i-1]%M;
	for(inv[1]=1,i=2;i<N;i++)
		inv[i]=(M-M/i)*inv[M%i]%M;
	for(inv[0]=1,i=1;i<N;i++)
		inv[i]=inv[i]*inv[i-1]%M;
}
void init(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		s[a]++;
	}
	for(i=1;i<N;i++)
		for(j=i<<1;j<N;j+=i)
			s[i]+=s[j];
}
ll C(int n,int m){
	if(n<m)return 0;
	return fac[n]*inv[m]%M*inv[n-m]%M;
}
bool check(int k){
	for(i=N-1;i;i--){
		f[i]=C(s[i],k);
		for(j=i<<1;j<N;j+=i)
			f[i]=(f[i]-f[j]+M)%M;
	}
	return f[1]>0;
}
void work(){
	for(k=1;k<=7;k++)
		if(check(k)){
			printf("%d\n",k);
			return;
		}
	printf("-1");
}
int main(){
	pre();
	init();
	work();
}