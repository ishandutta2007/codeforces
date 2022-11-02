#include<cstdio>
const int N=200002;
typedef long long ll;
int n,a,b,i,j,k,c[N][3];
int h[N],t[N],v[N],deg[N],rt;
int id[N],cnt,X,Y,Ans[N];
ll ans=1ll<<60,sum;
void add(int a,int b){
	t[++k]=h[a];
	h[a]=k;
	v[k]=b;
}
void init(){
	scanf("%d",&n);
	for(j=0;j<3;j++)
		for(i=1;i<=n;i++)
			scanf("%d",c[i]+j);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		deg[a]++;
		deg[b]++;
		add(a,b);
		add(b,a);
	}
}
void dfs(int i,int fa){
	id[++cnt]=i;
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa)
			dfs(v[j],i);
}
ll min(ll x,ll y){
	return x<y?x:y;
}
void G(int x,int y){
	sum=0;
	for(i=1;i<=n;i++){
		if(i%3==0)
			sum+=c[id[i]][x];
		if(i%3==1)
			sum+=c[id[i]][y];
		if(i%3==2)
			sum+=c[id[i]][3-x-y];
	}
	if(sum<ans){
		ans=min(ans,sum);
		X=x,Y=y;
	}
}
void Out(int x,int y){
	for(i=1;i<=n;i++){
		if(i%3==0)
			Ans[id[i]]=x+1;
		if(i%3==1)
			Ans[id[i]]=y+1;
		if(i%3==2)
			Ans[id[i]]=4-x-y;
	}
	for(i=1;i<=n;i++)
		printf("%d ",Ans[i]);
}
void work(){
	for(i=1;i<=n;i++)
		if(deg[i]>2){
			printf("-1");
			return;
		}
	for(i=1;i<=n;i++)
		if(deg[i]==1)
			rt=i;
	dfs(rt,0);
	G(0,1);
	G(0,2);
	G(1,0);
	G(1,2);
	G(2,0);
	G(2,1);
	printf("%lld\n",ans);
	Out(X,Y);
}
int main(){
	init();
	work();
	return 0;	
}