#include<cstdio>
const int N=10002;
int n,i,j,x,y,h[N],t[N],v[N],d[N],vis[N],k;
long long a[N];
void dfs(int i){
	vis[i]=1;
	printf("%I64d ",a[i]);
	for(int j=h[i];j;j=t[j])
		if(!vis[v[j]]){
			dfs(v[j]);
			return;
		}
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%I64d",a+i);
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i!=j){
				if(a[i]*2==a[j]){
					t[++k]=h[i];
					h[i]=k;
					v[k]=j;
					d[j]++;
				}
				if(a[i]%3==0&&a[j]==a[i]/3){
					t[++k]=h[i];
					h[i]=k;
					v[k]=j;
					d[j]++;
				}
			}
	for(i=1;i<=n;i++)
		if(!d[i])
			dfs(i);
}