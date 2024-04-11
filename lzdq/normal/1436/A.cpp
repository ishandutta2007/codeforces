#include<cstdio>
const int MAXN=1e6+5;
int n,m;
int a[MAXN];
int main(){
	int _;
	scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		int sum=0;
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),sum+=a[i];
		if(sum==m) puts("YES");
		else puts("NO");
	}
	return 0;
}