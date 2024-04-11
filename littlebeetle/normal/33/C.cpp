#include<cstdio>
const int N=100002;
int n,a,s,b,t;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d",&a);
		s+=a;
		if(b>0)
			b+=a;
		else
			b=a;
		if(b>t)
			t=b;
	}
	printf("%d",t+-(s-t));
}