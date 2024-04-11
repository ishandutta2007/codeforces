#include <cstdio>
#include <iostream>
#include <cmath>
int len,s,t,t1,t2,x,fx,tag1,tag2,T;
int calc1(){return t2*std::abs(t-s);}
void checktag(){
	if(x==s) tag1=true;
	if(x==t&&tag1) tag2=true;
}
int calc2(){
	tag1=0;tag2=0;T=0;
	checktag();
	for(;;){
		if(tag2) break;
		if(x==0&&fx==-1) fx=1;
		if(x==len&&fx==1) fx=-1;
		x+=fx;T++;
		checktag();
	}
	return t1*T;
}
int main(){
	scanf("%d%d%d%d%d%d%d",&len,&s,&t,&t1,&t2,&x,&fx);
	printf("%d\n",std::min(calc1(),calc2()));
}