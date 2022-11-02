#include<cstdio>
const int N=100002;
int n,k,x,y,s,i,fa[N];
int p(int x){
	return x==fa[x]?x:fa[x]=p(fa[x]);
}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		fa[i]=i;
	while(k--){
		scanf("%d%d",&x,&y);
		x=p(x);y=p(y);
		if(x==y)
			s++;
		else
			fa[x]=y;
	}
	printf("%d\n",s);
	
}