#include<cstdio>
int n,X,Y,x,y,t;
char s[3];
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s%d%d",s,&x,&y);
		if(x<y){
			t=x;x=y;y=t;
		}
		if(*s=='+'){
			if(x>X)X=x;
			if(y>Y)Y=y;
		}
		else
			printf("%s\n",(x>=X&&y>=Y)?"YES":"NO");
	}
	return 0;
}