#include<cstdio>
const int N=200002;
int n,i,l,p,a[N];
int main(){
	scanf("%d",&n);
	for(i=l=1;i<=n;i++){
		scanf("%d",a+i);
		if(a[i-1]*2<a[i])
			l=i;
		if(i-l+1>p)
			p=i-l+1;
	}
	printf("%d",p);
}