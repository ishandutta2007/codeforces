#include<cstdio>
int x,y,n,a,b,s;
int main(){
	scanf("%d%d%d",&x,&y,&n);
	for(a=0;a<=x;a++)
		for(b=0;b<=y;b++)
			if(a+b==n)
				s++;
	printf("%d",s);

}