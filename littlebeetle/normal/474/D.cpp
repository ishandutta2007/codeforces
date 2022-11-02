#include<cstdio>
const int N=100020,M=1000000007;
int n,k,f[N],i,a,b;
int main(){
	scanf("%d%d",&n,&k);
	f[0]=1;
	for(i=1;i<N;i++){
		f[i]=f[i-1];
		if(i>=k)//
			f[i]=(f[i]+f[i-k])%M;//
	}
	for(i=1;i<N;i++)
		f[i]=(f[i]+f[i-1])%M;
	while(n--){
		scanf("%d%d",&a,&b);
		printf("%d\n",(f[b]-f[a-1]+M)%M);
	}
}