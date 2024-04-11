#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int N=105;
const ll infl=0x3f3f3f3f3f3f3f3fll;

inline void Min(int &a,int b){if(b<a) a=b;}
inline void Min(ll &a,ll b){if(b<a) a=b;}
inline void Max(int &a,int b){if(b>a) a=b;}
inline void Max(ll &a,ll b){if(b>a) a=b;}

int n,m,k,c[N],v[N][N];
ll f[N][N][N];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n) scanf("%d",c+i);
	rep(i,1,n) rep(j,1,m) scanf("%d",v[i]+j);
	memset(f,0x3f,sizeof(f));
	if(c[1]) f[1][1][c[1]]=0;
	else rep(i,1,m) f[1][1][i]=v[1][i];
	rep(i,2,n) rep(j,1,i)
		if(c[i]){
			Min(f[i][j][c[i]],f[i-1][j][c[i]]);
			rep(k,1,m) if(k^c[i])
				Min(f[i][j][c[i]],f[i-1][j-1][k]);
		}
		else{
			rep(k,1,m){
				Min(f[i][j][k],f[i-1][j][k]+v[i][k]);
				rep(l,1,m) if(k^l)
					Min(f[i][j][k],f[i-1][j-1][l]+v[i][k]);
			}
		}
	ll ans=infl;
	rep(i,1,m) Min(ans,f[n][k][i]);
	if(ans!=infl) printf("%I64d\n",ans);
	else puts("-1");
}