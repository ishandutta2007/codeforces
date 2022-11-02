#include<cstdio>
int n,x,y,m;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d%d",&n,&x,&y);
	y*=5;
	m=n%y;
	while(n>=x){
		n-=x;
		m=min(m,n%y);
	}
	printf("%d",m);
	//while(1);
}