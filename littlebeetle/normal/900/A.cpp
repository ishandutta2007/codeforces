#include<cstdio>
int n,x,y,s1,s2;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		if(x<0)
			s1++;
		else
			s2++;
	}
	if(s1<=1||s2<=1)
		printf("Yes");
	else
		printf("No");
}