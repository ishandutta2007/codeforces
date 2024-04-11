#include<cstdio>
typedef long long ll;
ll t,n,l,r,opt,i;
int main(){
	scanf("%lld",&t);
	while(t--){
		scanf("%d%d%d",&n,&l,&r);
		opt=0;
		i=n/l;
		printf("%s\n",i*l<=n&&i*r>=n?"Yes":"No");
	}
}