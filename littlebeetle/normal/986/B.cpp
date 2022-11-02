#include<cstdio>
const int N=1000002;
int n,i,a,x,t[N],s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		for(x=a+1;x<=n;x+=x&-x)
			s+=t[x];
		s&=1;
		for(x=a;x;x-=x&-x)
			t[x]--;
	}
	if(s==3*n%2)
		printf("Petr");
	else
		printf("Um_nik");
}