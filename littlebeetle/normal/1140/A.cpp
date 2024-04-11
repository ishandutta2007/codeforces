#include<cstdio>
int n,i,a,s,p;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		p=a>p?a:p;
		if(i==p)
			s++;
	}
	printf("%d",s);
	//while(1);
}