#include<cstdio>
const int N=10002,M=15000002;
int n,a[N],x[N*30],i,j,k,t[M],o;
bool f[N]={1,1};
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	for(i=2;i<N;i++){
		if(!f[i])
			a[++k]=i;
		for(j=1;j<=k&&i*a[j]<N;j++){
			f[i*a[j]]=1;
			if(i%a[j]==0)
				break;
		}
	}
	for(i=1;i<=n;i++)
		scanf("%d",x+i);
	o=x[1];
	for(i=2;i<=n;i++)
		o=gcd(o,x[i]);
	for(i=1;i<=n;i++){
		x[i]/=o;
		j=x[i];
		for(k=1;a[k]*a[k]<=j;k++)
			if(j%a[k]==0){
				t[a[k]]++;
				while(j%a[k]==0)
					j/=a[k];
			}
		if(j!=1)
			t[j]++;
	}
	k=0;
	for(i=1;i<M;i++)
		if(t[i]>k)
			k=t[i];
	if(k==0)
		printf("-1");
	else
		printf("%d",n-k);
	return 0;
}