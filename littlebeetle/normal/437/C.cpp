#include<cstdio>
const int N=100002;
int n,m,c[N],i,a,b,ans;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",c+i);
	while(m--){
		scanf("%d%d",&a,&b);
		ans+=c[a]<c[b]?c[a]:c[b];
	}
	printf("%d",ans);
}