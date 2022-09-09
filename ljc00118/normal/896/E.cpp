#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<cstdio>
#define F for(int i=l;i<=r;++i)
int V[100002];float x;
main(){
	int n,m,l,r,A,T;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&V[i]);
	while(m--){
		scanf("%d%d%d%f",&T,&l,&r,&x);
		if(T==1)F V[i]-=V[i]>x?x:0;
		else{A=0;F V[i]==x?++A:0;printf("%d\n",A);}
	}
}