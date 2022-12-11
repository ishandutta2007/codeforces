#include<cstdio>

using namespace std;

int f[400001];
int ff(int u){
	return f[u]^u?f[u]=ff(f[u]):u;
}
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n+m;i++)
		f[i]=i;
	for(int i=1;i<=k;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		f[ff(u)]=ff(n+v);
	}
	int ans=0;
	for(int i=1;i<=n+m;i++)
		if(ff(i)==i)ans++;
	printf("%d\n",ans-1);
}