#include<cstdio>
const int N=1002,M=1000000007;
char s[N];
int n,i,j,p[N],c[N][N],f[N],cnt[N],k,sum,ans;
void Prepare(){
	for(i=0;i<N;i++){
		c[i][0]=1;
		for(j=1;j<=i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%M;
	}
	cnt[1]=1;
	f[0]=-100;
	for(i=2;i<N;i++){
		cnt[i]=cnt[i>>1]+(i&1);
		f[i]=f[cnt[i]]+1;
	}
}
void work(){
	for(;i;i--)
		if(p[i]==1){
			for(j=0;j<i;j++)
				if(f[sum+j]+1==k)
					ans=(ans+c[i-1][j])%M;
			sum++;
		}
	if(f[sum]+1==k)
		ans=(ans+1)%M;
	if(k==1)
		ans=(ans+M-1)%M;
	printf("%d",ans);
}
int main(){
	Prepare();
	scanf("%s%d",s+1,&k);
	if(k==0){
		printf("%d",1);
		return 0;
	}
	while(s[n+1])
		n++;
	for(i=1;i<=n;i++)
		p[i]=s[n-i+1]-48;
	work();
}