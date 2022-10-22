#include<cstdio>
const int MAXN=1005;
int n,m,a[MAXN];
int main(){
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		int sum=0;
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),sum+=a[i];
		if(sum>m) sum=m;
		printf("%d\n",sum);
	}
	return 0;
}