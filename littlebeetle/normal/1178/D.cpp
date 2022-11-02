#include<cstdio>
const int N=10002;
int n,m,i,x[N],y[N];
bool isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++)
		x[i]=i,y[i]=i+1;
	x[n]=n;y[n]=1;
	m=n;i=1;
	while(!isprime(m)){
		m++;
		x[m]=i;y[m]=i+n/2;
		i++;
	}
	printf("%d\n",m);
	for(i=1;i<=m;i++)
		printf("%d %d\n",x[i],y[i]);
}