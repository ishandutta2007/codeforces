#include<cstdio>
const int N=100002;
int n,y,i,k,a[N];
int main(){
	scanf("%d",&n);
	if((n&1))
		a[++k]=0;
	else{
		y=n;
		i=0;
		while(!(y&1))
			y>>=1,i++;
		a[++k]=i;
		n^=(1<<i)-1;
	}		
	while((n+1)!=((n+1)&-(n+1))){
		n++;
		++k;
		y=n;
		i=0;
		while(!(y&1))
			y>>=1,i++;
		a[++k]=i;
		n^=(1<<i)-1;
	}
	printf("%d\n",k);
	for(i=1;i<=k;i+=2)
		printf("%d ",a[i]);
}