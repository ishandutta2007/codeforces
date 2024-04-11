#include<cstdio>
const int N=200002;
char x[N],y[N];
int T,n,m,i,j,k;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s%s",x+1,y+1);
		for(n=0;x[n+1];n++);
		for(m=0;y[m+1];m++);
		for(i=0;y[m-i]=='0';i++);
		for(j=i;x[n-j]=='0';j++);
		printf("%d\n",j-i);
	}
	return 0;
}