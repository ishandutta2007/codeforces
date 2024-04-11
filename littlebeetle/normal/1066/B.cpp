#include<cstdio>
const int N=2002,inf=1<<29;
int n,r,a[N],f[N],i,j,p;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&r);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<N;i++)
		f[i]=inf;
	for(i=1;i<=n;i++)
		if(a[i]){
			p=inf;
			for(j=i-r;j<=i+r-1;j++)
				if(j>=0&&j<N)
					p=min(p,f[j]);
			for(j=i-r+1;j<=i+r-1;j++)
				if(j>=0&&j<N)
				f[j]=min(f[j],p+1);			
		}
	printf("%d",f[n]>=inf?-1:f[n]);
}