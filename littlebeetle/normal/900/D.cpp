#include<cstdio>
const int N=30,M=1000000007;
int x,y,i,j,d[N],cnt,ans;
int ksm(int x,int p){
	int s=1;
	while(p){
		if(p&1)
			s=1ll*x*s%M;
		p>>=1;
		x=1ll*x*x%M;
	}
	return s;
}
void dfs(int i,int val,int sum){
	if(i==cnt+1){
		ans=(ans+(sum%2?-1:1)*ksm(2,y/val-1))%M;
		return;
	}
	dfs(i+1,val,sum);
	dfs(i+1,val*d[i],sum+1);
}
int main(){
	scanf("%d%d",&x,&y);
	if(y%x!=0){
		printf("0");
		return 0;
	}
	y=x=y/x;
	for(i=2;i*i<=x;i++)
		if(x%i==0){
			d[++cnt]=i;
			while(x%i==0)
				x/=i;
		}
	if(x>1)
		d[++cnt]=x;
	dfs(1,1,0);
	printf("%d",(ans+M)%M);
}