#include<cstdio>
const int p[]={0,1,1,2,2};
int n,x,y,z;
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		z=x>y?x-y:y-x;
		printf("%d\n",z/5+p[z%5]);
	}
//	while(1);
}