#include<cstdio>
#include<algorithm>
using namespace std;
const int N=37,M=1000002;
int n,m,mid,i,j,a[N],ans,f[M],g[M],cnf,cng;
void dfs1(int i,int s){
	if(i==mid+1){
		f[++cnf]=s;
		return;
	}
	dfs1(i+1,s);
	dfs1(i+1,(s+a[i])%m);
}
void dfs2(int i,int s){
	if(i==n+1){
		g[++cng]=s;
		return;
	}
	dfs2(i+1,s);
	dfs2(i+1,(s+a[i])%m);
}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	if(n==1){
		printf("%d\n",a[1]%m);
		return 0;
	}
	mid=n/2;
	dfs1(1,0);
	dfs2(mid+1,0);
	sort(f+1,f+cnf+1);
	sort(g+1,g+cng+1);
	ans=(f[cnf]+g[cng])%m;
	for(i=1,j=cng;i<=cnf;i++){
		while(f[i]+g[j]>=m)
			j--;
		ans=max(ans,f[i]+g[j]);
	}
	printf("%d",ans);
}