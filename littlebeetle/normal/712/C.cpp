#include<cstdio>
int y,x,a,b,c,t,cnt;
int main(){
	scanf("%d%d",&y,&x);
	if(x>y)
		t=y,y=x,x=t;
	a=b=c=x;
	while(a<y){
		cnt++;
		a=b+c-1;
		if(a>y)
			a=y;
		if(c<a)
			t=a,a=c,c=t;
		if(b<a)
			t=b,b=a,a=t;
	}
	printf("%d",cnt);
}