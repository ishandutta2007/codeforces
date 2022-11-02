#include<cstdio>
const int INF=1<<30,P=1900;
int l,r,n,x,c,d;
int max(int x,int y){
	return x>y?x:y;
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d",&n);
	l=-INF;
	r=INF;
	while(n--){
		scanf("%d%d",&c,&d);
		if(d==1)
			l=max(l,P-x);
		else
			r=min(r,P-x);
		x+=c;
	}
	if(r==INF){
		printf("Infinity");
		return 0;
	}
	if(l>=r){
		printf("Impossible");
		return 0;
	}
	printf("%d",r-1+x);
}