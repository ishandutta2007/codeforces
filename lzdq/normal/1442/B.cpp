#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5,Mod=998244353;
int n,m,ans;
int a[MAXN],p[MAXN],b[MAXN];
int vis[MAXN],pre[MAXN],suf[MAXN];
int Calc(){
	int ans=1;
	for(int i=1; i<=m; i++){
		if(vis[a[p[b[i]]-1]]&&vis[a[p[b[i]]+1]]) return 0;
		if(vis[a[p[b[i]]-1]]+vis[a[p[b[i]]+1]]) vis[a[p[b[i]]]]=0;
		else{
			vis[a[p[b[i]]]]=0;
			ans=ans*2%Mod;
		}
	}
	return ans;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++){
			scanf("%d",a+i),p[a[i]]=i;
			vis[i]=0;
			pre[i]=i-1;
			suf[i]=i+1;
		}
		vis[0]=1;
		vis[n+1]=0;
		a[n+1]=0;
		p[n+1]=0;
		for(int i=1; i<=m; i++){
			scanf("%d",b+i);
			vis[b[i]]=1;
		}
		printf("%d\n",Calc());
	}
	return 0;
}