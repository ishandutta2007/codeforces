#include<cstdio>
const int N=10002;
int T;
int n,a[N],i;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			scanf("%1d",a+i);
		for(i=1;i<=n;i++)
			if(a[i]==8)
				break;
		printf("%s\n",n-i>=10?"YES":"NO");
	}
}