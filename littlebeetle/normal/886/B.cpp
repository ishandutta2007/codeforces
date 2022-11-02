#include<cstdio>
const int N=200002;
int n,i,k,a,t[N];
int main(){
	for(i=0;i<N;i++)
		t[i]=N;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a);
		t[a]=i;
	}
	for(i=1;i<N;i++)
		if(t[i]<t[k])
			k=i;
	printf("%d",k);
	//while(1);
}