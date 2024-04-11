#include<cstdio>
const int M=998244353;
int n,m,ans=1;
int main(){
	scanf("%d%d",&n,&m);
	n+=m;
	while(n--)
		ans=ans*2%M;
	printf("%d",ans);
}