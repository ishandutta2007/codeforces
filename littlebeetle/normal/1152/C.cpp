#include<cstdio>
int a,b,c,d,A,B,ans=1<<30;
long long alcm=1ll<<61,lcm;
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void p(int x){
	A=(a+x-1)/x*x;
	B=(b+x-1)/x*x;
	lcm=1ll*A*B/gcd(A,B);
	if(lcm<alcm||(lcm==alcm&&(A-a)<ans))
		alcm=lcm,ans=A-a;
}
int main(){
	scanf("%d%d",&a,&b);
	if(a==b){
		printf("0");
		return 0;
	}
	c=a>b?a-b:b-a;
	for(d=1;d*d<=c;d++)
		if(c%d==0){
			p(d);
			p(c/d);
		}
	printf("%d",ans);
}