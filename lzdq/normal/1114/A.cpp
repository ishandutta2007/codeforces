#include<cstdio>
int x,y,z;
int a,b,c;
inline bool calc(){
	a-=x;
	if(a<0) return 0;
	b=b+a-y;
	if(b<0) return 0;
	c=c+b-z;
	return c>=0;
}
int main(){
	scanf("%d%d%d",&x,&y,&z);
	scanf("%d%d%d",&a,&b,&c);
	if(calc()) puts("Yes");
	else puts("No");
	return 0;
}