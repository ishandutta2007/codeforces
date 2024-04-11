#include<cstdio>
int n;
bool isprime(int x){
	for(int i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}
int ksm(int x,int p){
	int s=1;
	while(p){
		if(p&1)
			s=1ll*s*x%n;
		p>>=1;
		x=1ll*x*x%n;
	}
	return s;
}
int main(){
	scanf("%d",&n);
	if(n==1){
		printf("YES\n1");
		return 0;
	}
	if(n==4){
		printf("YES\n1\n3\n2\n4");
		return 0;
	}
	if(isprime(n)){
		printf("YES\n1\n");
		for(int i=2;i<n;i++)
			printf("%d\n",1ll*i*ksm(i-1,n-2)%n);
		printf("%d",n);	
	}
	else{
		printf("NO");
	}
}