#include<cstdio>
int N,K,A[1000005];
int main(){
	scanf("%d%d",&N,&K);
	int S=0;
	for(int i=1;i<=N;++i) scanf("%d",A+i), S+=A[i];
	if(S%K!=0) {puts("No"); return 0;}
	int D=S/K;
	for(int i=1;i<=N;++i) A[i]+=A[i-1];
	int C=0;
	for(int i=1;i<=N;++i) if(A[i]%D==0) ++C;
	if(C!=K) {puts("No"); return 0;}
	puts("Yes");
	int j=0;
	for(int i=1;i<=N;++i) if(A[i]%D==0) printf("%d ",i-j), j=i;
}