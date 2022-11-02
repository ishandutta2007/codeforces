#include<cstdio>
const int N=102;
int n,m,h,i,j,a[N],b[N];
bool f;
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d%d",&n,&m,&h);
	for(i=1;i<=m;i++)
		scanf("%d",b+i);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			scanf("%d",&f);
			printf("%d ",f?min(a[i],b[j]):0);
		}
		printf("\n");
	}
	//while(1);
}