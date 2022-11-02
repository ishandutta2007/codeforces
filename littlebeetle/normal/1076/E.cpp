#include<cstdio>
const int N=600002;
int n,m,i,j,k,a,b,h[N],t[N],v[N],d[N],H[N],T[N],D[N],X[N];
long long c[N],S[N];
void add(int x,int y){
	while(x<=n)
		c[x]+=y,x+=x&-x;
}
void sum(int x,int i){
	while(x)
		S[i]+=c[x],x-=x&-x;
}
void dfs(int i,int fa){
	int j;
	for(j=H[i];j;j=T[j])
		add(d[i],X[j]),add(d[i]+D[j]+1,-X[j]);
	sum(d[i],i);
	for(j=h[i];j;j=t[j])
		if(v[j]!=fa)
			d[v[j]]=d[i]+1,dfs(v[j],i);
	for(j=H[i];j;j=T[j])
		add(d[i],-X[j]),add(d[i]+D[j]+1,X[j]);	
}
int main(){
	scanf("%d",&n);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	scanf("%d",&m);
	k=0;
	while(m--){
		scanf("%d",&a);
		T[++k]=H[a];H[a]=k;
		scanf("%d%d",D+k,X+k);
	}
	d[1]=1;
	dfs(1,0);
	for(i=1;i<=n;i++)
		printf("%lld ",S[i]);
	return 0;
}