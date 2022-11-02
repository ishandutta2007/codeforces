#include<cstdio>
#include<map>
using namespace std;
const int N=22;
typedef long long ll;
struct p{
	int i;
	ll j;
	bool operator<(const p &k)const{
		if(k.i!=i)return k.i<i;
		return k.j<j;
	}
};
map<p,int>mp;
int n,m,i,j;
ll a[N][N],k,ans;
void dfs(int i,int j,ll x){
	if(i+j-2==n-1){
		mp[(p){i-j,x}]++;
		return;
	}
	if(i<n)
		dfs(i+1,j,x^a[i+1][j]);
	if(j<m)
		dfs(i,j+1,x^a[i][j+1]);
}
void rdfs(int i,int j,ll x){
	if(i+j-2==n-1){
		ans+=mp[(p){i-j,x^k}];
		return;
	}
	x^=a[i][j];
	if(i>1)
		rdfs(i-1,j,x);
	if(j>1)
		rdfs(i,j-1,x);
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%lld",a[i]+j);
	dfs(1,1,a[1][1]);
	rdfs(n,m,0);
	printf("%lld\n",ans);
}