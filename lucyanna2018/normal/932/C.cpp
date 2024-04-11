#include<cstdio>
int n,a[1011111];
void proc1(int w){
	for(int i=1; i<w; i++){
		a[n+i] = n+(i+1);
	}
	a[n+w] = n+1;
	n += w;
}
void proc(int A,int cntA,int B,int cntB){
	for(int i=0; i<cntA; i++)proc1(A);
	for(int i=0; i<cntB; i++)proc1(B);
	for(int i=1; i<=n; i++)
		printf("%d%c",a[i],i<n?' ':'\n');
}
int main(){
	int N,A,B;
	scanf("%d%d%d",&N,&A,&B);
	for(int i=0; A*i<=N; i++)
		if((N-A*i)%B==0){
			proc(A, i, B, (N-A*i)/B);
			return 0;
		}
	puts("-1");
	return 0;
}