#include<cstdio>
const int N=1000002;
int n,i,j,k,a[N],d[N],A,B,C,cnt[N];
long long ans;
bool f[N];
int main(){
	d[1]=1;
	for(i=2;i<N;i++){
		if(!f[i])a[k++]=i,d[i]=2,cnt[i]=2;
		for(j=0;(!j||i%a[j-1])&&i*a[j]<N;j++){
			f[i*a[j]]=1;
			if(i%a[j])d[i*a[j]]=d[i]*2,cnt[i*a[j]]=2;
			else d[i*a[j]]=d[i]/cnt[i]*(cnt[i]+1),cnt[i*a[j]]=cnt[i]+1;
		}
	}
	scanf("%d%d%d",&A,&B,&C);
	for(i=1;i<=A;i++)
		for(j=1;j<=B;j++)
			for(k=1;k<=C;k++)
				ans+=d[i*j*k];
	printf("%lld",ans%1073741824);
	//while(1);
}