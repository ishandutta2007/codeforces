#include <cstdio>
int a,b,n;
int f[32000][30],tag[32000][30];
int solve(int a,int b){
	long long mult=1;
	for(int i=1;i<=b;i++){
		mult*=a;
		if(mult>=n) return 1;
	}
	if((1<<b)>=n) return 0;
	if(a*a>=n) return (n-a)&1?-1:1;
	if(tag[a][b]==233) return f[a][b];
	int res;
	if(solve(a,b+1)==1&&solve(a+1,b)==1) res=-1;
	else if(solve(a,b+1)==-1||solve(a+1,b)==-1) res=1;
	else res=0;
	tag[a][b]=233;
	return f[a][b]=res;
}
int main(){
	scanf("%d%d%d",&a,&b,&n);
	printf(solve(a,b)==1?"Masha":(solve(a,b)==-1?"Stas":"Missing"));
}