#include<cstdio>
const int N=200002;
typedef long long ll;
ll n,m,P,a,b,i,j,k,h[N],t[N],v[N],cnt,vis[N],sum,ans=1;
void dfs(int i){
	vis[i]=1;
	sum++;
	for(int j=h[i];j;j=t[j])
		if(!vis[v[j]])
			dfs(v[j]);
}
int main(){
	scanf("%lld%lld%lld",&n,&m,&P);
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	for(i=1;i<=n;i++)
		if(!vis[i]){
			sum=0;
			dfs(i);
			cnt++;
			ans=ans*sum%P;
		}
	if(cnt==1){
		printf("%d",1%P);
		return 0;
	}
	cnt-=2;
	while(cnt--){
		ans=ans*n%P;
	}
	printf("%lld",ans);
}