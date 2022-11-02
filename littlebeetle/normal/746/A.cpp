#include<cstdio>
int a,b,c;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d%d",&a,&b,&c);
	printf("%d",7*min(a,min(b>>1,c>>2)));
}