#include<cstdio>
const int N=200002;
int n,m,i,j,k,a,b,h[N],t[N],v[N],s[N],f[N],F[N],c[N],ans;
int max(int x,int y){
	return x>y?x:y;
}
void dfs(int i,int fa){
	s[i]=1;
	if(c[i])
		f[i]=f[fa]+1;
	F[i]=max(f[i],F[fa]);
	for(int j=h[i];j;j=t[j])
		if(v[j]!=fa){
			dfs(v[j],i);
			s[i]+=s[v[j]];
		}
	if(s[i]==1&&F[i]<=m)
		ans++;
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",c+i);
	for(i=1;i<n;i++){
		scanf("%d%d",&a,&b);
		t[++k]=h[a];h[a]=k;v[k]=b;
		t[++k]=h[b];h[b]=k;v[k]=a;
	}
	dfs(1,0);
	printf("%d",ans);
}