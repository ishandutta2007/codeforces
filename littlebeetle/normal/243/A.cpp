#include<cstdio>
const int N=2000020;
int n,i,j,s,a[N],L[N],R[N];
bool p[N];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		L[i]=i-1;
		R[i]=i+1;
		for(j=i;j;j=L[j]){
			a[j]|=a[i];
			p[a[j]]=1;
			if(j!=i&&a[j]==a[R[j]]){
				L[R[j]]=L[j];
				R[L[j]]=R[j];
				j=R[j];
			}
		}
	}
	for(i=0;i<N;i++)
		s+=p[i];
	printf("%d",s);
}