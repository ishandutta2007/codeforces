#include<cstdio>
const int N=1002;
int n,m,i,f[N],s[N],ans,k,j,o;
int p(int x){
	return x==f[x]?x:f[x]=p(f[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+m;i++)
		f[i]=i;
	for(i=1;i<=n;i++){
		scanf("%d",&k);
		o+=!k;
		while(k--){
			scanf("%d",&j);
			j+=n;
			if(p(i)!=p(j))
				f[f[i]]=j;
		}
	}
	if(o==n){
		printf("%d",n);
		return 0;
	}
	for(i=1;i<=n;i++)
		s[p(i)]=1;
	for(i=1;i<=n+m;i++)
		ans+=s[i];
	printf("%d",ans-1);
}