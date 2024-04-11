#include<cstdio>
const int MAXN=1e6+5;
int n,m,p,a[MAXN],b[MAXN];
int main(){
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1; i<=n; i++){
		scanf("%d",a+i);
		a[i]%=p;
		if(a[i]&&!a[0]) a[0]=i;
	}
	for(int i=1; i<=m; i++){
		scanf("%d",b+i);
		b[i]%=p;
		if(b[i]&&!b[0]) b[0]=i;
	}
	printf("%d\n",*a+*b-2);
	return 0;
}