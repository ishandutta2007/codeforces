// luogu-judger-enable-o2
#include<cstdio>
int n,i,a,b,o,s=1<<30;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		a=i;b=n;o=0;
		while(a%b&&b%a){
			if(a>b)
				o+=a/b,a%=b;
			else
				o+=b/a,b%=a;
		}
		if(a==1||b==1){
			if(a>b)
				o+=a-1;
			else
				o+=b-1;
			s=o<s?o:s;
		}
	}
	printf("%d",s);
}