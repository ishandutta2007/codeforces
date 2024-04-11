#include<cstdio>
const int N=5002;
int n,i,j,g[N],f[N],ans;
int min(int x,int y){
	return x<y?x:y;
}
bool isprime(int p){
	if(p==1)return 0;
	for(int i=2;i*i<=p;i++)
		if(p%i==0)
			return 0;
	return 1;
}
int main(){
	scanf("%d",&n);
	if(isprime(n)){
		printf("1");
		return 0;
	}
	if(n%2==0||isprime(n-2)){
		printf("2");
		return 0;
	}
	printf("3");
}