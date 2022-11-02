#include<cstdio>
int n,x,y,p;//
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		if(x+y>p)
			p=x+y;
	}
	printf("%d",p);
	return 0;
}