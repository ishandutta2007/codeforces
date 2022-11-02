#include<cstdio>
int l,r,x,i;
bool f[10];
bool ok(int x){
	for(i=0;i<10;i++)
		f[i]=0;
	while(x){
		if(f[x%10])
			return 0;
		f[x%10]=1;
		x/=10;
	}
	return 1;
}
int main(){
	scanf("%d%d",&l,&r);
	for(x=l;x<=r;x++)
		if(ok(x)){
			printf("%d",x);
			//while(1);
			return 0;
		}
	printf("-1");
		//while(1);
}