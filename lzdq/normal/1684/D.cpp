#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,k,a[MAXN];
vector<ll> f[MAXN<<2];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
void Dfs(int k,int l,int r){
	f[k].resize(r-l+2);
	f[k][0]=0;
	if(l==r){
		f[k][1]=a[l];
		return ;
	}
	int mid=l+r>>1;
	Dfs(ls);
	Dfs(rs);
	int p1=0,p2=0;
	while(p1+1<f[lc].size()||p2+1<f[rc].size()){
		if(p1+1==f[lc].size() || p2+1<f[rc].size()&&f[lc][p1+1]+f[rc][p2]+(mid-l+1ll-(p1+1))*p2>f[lc][p1]+f[rc][p2+1]+(mid-l+1ll-p1)*(p2+1)) p2++;
		else p1++;
		f[k][p1+p2]=f[lc][p1]+f[rc][p2]+(mid-l+1ll-p1)*p2;
	}
	return ;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&k);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i);
		Dfs(1,1,n);
		printf("%lld\n",f[1][n-k]);
	}
	return 0;
}