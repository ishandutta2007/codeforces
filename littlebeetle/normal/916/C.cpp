#include<cstdio>
int n,m,i,j,k;
bool isprime(int a){
	for(int i=2;i*i<=a;i++)
		if(a%i==0)
			return 0;
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	k=n;
	while(!isprime(k))
		k++;
	printf("%d %d\n",k,k);
	for(i=1;i<n-1;i++)
		printf("%d %d %d\n",i,i+1,1);
	printf("%d %d %d\n",n-1,n,k-(n-2));
	m-=(n-1);
	i=1;j=3;
	while(m--){
		printf("%d %d %d\n",i,j,1000000000);
		j++;
		if(j>n)
			i++,j=i+2;
	}
}