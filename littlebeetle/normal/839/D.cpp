#include<cstdio>
const int N=1000020,M=1000000007;
int n,i,j,k,a,s[N],f[N],cnt,ans;
void init(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		s[a]++;
	}
}
int ksm(int x,int p){
	int s=1;
	while(p){
		if(p&1)
			s=1ll*s*x%M;
		p>>=1;
		x=1ll*x*x%M;
	}
	return s;
}
void work(){
	for(k=N-1;k>1;k--){
		cnt=0;
		for(i=k;i<N;i+=k)
			cnt+=s[i];
		if(cnt){
			f[k]=1ll*cnt*ksm(2,cnt-1)%M;
			for(i=k+k;i<N;i+=k)
				f[k]=(f[k]+M-f[i])%M;
		}
		ans=(ans+1ll*f[k]*k)%M;
	}
	printf("%d",ans);
}
int main(){
	init();
	work();
	//while(1);
}