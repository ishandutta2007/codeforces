#include<cstdio>
const int N=1002;
int w,h,u1,h1,u2,h2,f[N],i;
int main(){
	scanf("%d%d%d%d%d%d",&w,&h,&u1,&h1,&u2,&h2);
	f[h1]+=u1;
	f[h2]+=u2;
	for(i=h;i;i--){
		w+=i;
		w-=f[i];
		if(w<0)
			w=0;
	}
	printf("%d",w);
	return 0;
}