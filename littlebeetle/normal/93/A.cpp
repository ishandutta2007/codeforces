#include<cstdio>
int n,m,a,b,xa,ya,xb,yb;
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	xa=(a-1)/m;
	ya=a-xa*m;
	xb=(b-1)/m;
	yb=b-xb*m;
	if(b==n)
		yb=m;
	if(xa==xb||(ya==1&&yb==m)){
		printf("1");
		return 0;
	}
	if((ya==yb+1)||ya==1||yb==m||xa+1==xb){
		printf("2");
		return 0;
	}
	printf("3");
	return 0;
}