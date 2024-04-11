#include<cstdio>
const int N=1002;
int T,n,a[N],i,k,s;
bool ok(int x){
	int s=0;
	for(i=1;i<=n;i++)
		if(a[i]>=x)
			s++;
	return s>=x;
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%d",a+i);
		for(k=1;ok(k);k++);
		printf("%d\n",k-1);
	}
}