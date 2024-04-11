#include<cstdio>
const int N=200002;
int n,k,i,j,a[N];
void init(){
	scanf("%d%d",&n,&k);
}
void swap(int &x,int &y){
	int t=x;x=y;y=t;
}
void work(){
	for(i=1;i<=n*2;i++)
		a[i]=i;
	for(i=1;i<=k;i++){
		j=i*4;
		swap(a[j-1],a[j]);
	}
	for(i=1;i<=n*2;i++)
		printf("%d ",a[i]);
}
int main(){
	init();
	work();
	return 0;
}