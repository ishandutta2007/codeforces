#include<stdio.h>
int main(){
	int res=0,D,R,N,x,y,r;
	for(scanf("%d%d%d",&R,&D,&N); N--;){
		scanf("%d%d%d",&x,&y,&r);
		int d2 = x * x + y * y;
		if(d2 >= (r + R-D) * (r+R-D) && r <= R && d2 <= (R-r)*(R-r))res++;
	}
	printf("%d\n",res);
	return 0;
}