#include<cstdio>
int q,a,b,n,s;
int main(){
	scanf("%d",&q);
	while(q--){
		scanf("%d%d%d%d",&a,&b,&n,&s);
		if(s/n<=a)
			s%=n;
		else
			s-=n*a;
		printf("%s\n",s<=b?"YES":"NO");
	}
}