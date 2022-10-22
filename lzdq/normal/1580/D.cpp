#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=4005;
const ll INF=1ll<<60;
int n,m,a[MAXN];
ll f[MAXN][MAXN];
int Dfs(int l,int r){
	if(l>r) return 0;
	if(l==r){
		f[l][0]=0;
		f[l][1]=(m-1ll)*a[l];
		return l;
	}
	int w=l;
	for(int i=l+1; i<=r; i++)
		if(a[i]<a[w]) w=i;
	ll *f1=f[Dfs(l,w-1)],*f2=f[Dfs(w+1,r)];
	for(int i=1; i<=r-l+1; i++)
		f[w][i]=-INF;
	int l1=w-l,l2=r-w;
	for(int i=0; i<=l1; i++)
		for(int j=0; j<=l2; j++)
			f[w][i+j]=max(f[w][i+j],f1[i]+f2[j]-2ll*i*j*a[w]);
	for(int i=r-l+1; i; i--)
		f[w][i]=max(f[w][i],f[w][i-1]+a[w]*(m+1ll-i*2));
	return w;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",a+i);
	printf("%lld\n",f[Dfs(1,n)][m]);
	return 0;
}