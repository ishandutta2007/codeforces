#include<cstdio>
const int N=100002;
int x,y,z;
int main(){
	scanf("%d%d%d",&x,&y,&z);
	if(x==y&&z==0){
		printf("0");
		return 0;
	}
	if(x+z>y&&x>y+z){
		printf("+");
		return 0;
	}
	if(x<y+z&&x+z<y){
		printf("-");
		return 0;
	}
	printf("?");
}