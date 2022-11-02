#include<cstdio>
const int N=100002;
int n,m,a[N],f[N],b[N],i,x,y;
long long ans;
int p(int x){
	return f[x]==x?x:f[x]=p(f[x]);
}
int min(int x,int y){
	return x<y?x:y;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),f[i]=i,b[i]=1<<30;
	while(m--){
		scanf("%d%d",&x,&y);
		if(p(x)!=p(y))
			f[p(x)]=y;
	}
	for(i=1;i<=n;i++)
		b[p(i)]=min(b[p(i)],a[i]);
	for(i=1;i<=n;i++)
		if(b[i]!=1<<30)
			ans+=b[i];
	printf("%I64d",ans);
	//while(1);
}