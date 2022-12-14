#include<cstdio>
int n,m,i,j,k,ans;
void input(){
	ans=0;
	scanf("%d%d",&n,&m);
	while(1){
		if(n<m) n++,m-=2;
		else n-=2,m++;
		if(n<0||m<0) break;
		ans++;
		if(n<=0||m<=0) break;
	}
}
void output(){
	printf("%d",ans);
}
int main(){
	input();
	output();
}