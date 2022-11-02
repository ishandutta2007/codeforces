#include<cstdio>
const int N=10002;
int n,a[N],i,s;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	for(i=3;i<=n;i++)
		if(a[i]==1&&a[i-1]==0&&a[i-2]==1){
			a[i]=0;
			s++;
		}
	printf("%d",s);
	return 0;
}