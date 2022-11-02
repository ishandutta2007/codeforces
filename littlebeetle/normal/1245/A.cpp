#include<cstdio>
int n,a,b;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&a,&b);
		printf("%s\n",gcd(a,b)>1?"Infinite":"Finite");
	}
	//while(1);
}