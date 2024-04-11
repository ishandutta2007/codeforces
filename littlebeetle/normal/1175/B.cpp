#include<cstdio>
#include<cstdlib>
typedef long long ll;
const long long P=(1ll<<32)-1;
ll t,x;
char s[10];
ll dfs(){
	ll x=0,a;
	while(t){
		t--;
		scanf("%s",s);
		if(*s=='a')
			x++;
		if(*s=='f'){
			scanf("%lld",&a);
			x=x+a*dfs();
		}
		else{
			if(*s=='e')
				return x;
		}
		if(x>P){
			printf("OVERFLOW!!!");
			exit(0);
		}
	}
	if(x>P){
		printf("OVERFLOW!!!");
		exit(0);
	}
	return x;
}
int main(){
	scanf("%lld",&t);
	x=dfs();
	if(x>P){
		printf("OVERFLOW!!!");
		exit(0);
	}
	printf("%lld",x);
	//while(1);
}