#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=1e5+5;
int n,a[MAXN],f[MAXN],g[MAXN];
int ans;
void Dfs(int l,int r){
	int mx=-100;
	for(int i=l; i<=r; i++)
		mx=max(mx,a[i]);
	f[l-1]=0;
	for(int i=l; i<=r; i++)
		f[i]=max(f[i-1]+a[i],0);
	g[r+1]=0;
	for(int i=r; i>=l; i--)
		g[i]=max(g[i+1]+a[i],0);
	int res=-1e9;
	for(int i=l; i<=r; i++)
		if(a[i]==mx) ans=max(ans,f[i-1]+g[i+1]);
	int w=0;
	for(int i=l; i<=r; i++)
		if(a[i]==mx){
			if(w) Dfs(w,i-1);
			w=0;
		}else if(!w) w=i;
	if(w) Dfs(w,r);
	return ;
}
int main(){
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	Dfs(1,n);
	printf("%d\n",ans);
	return 0;
}