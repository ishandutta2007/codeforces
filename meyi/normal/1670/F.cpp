#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1010,mod=1e9+7;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int n;
ll C[maxn][maxn],f[maxn][2],g[maxn][2],z;
inline void init(int sz){
	C[0][0]=1;
	for(ri i=1;i<=sz;++i){
		C[i][0]=C[i][i]=1;
		for(ri j=1;j<i;++j)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
}
inline ll calc(ll k){
	memset(g,0,sizeof g);
	g[0][0]=1;
	for(ri i=0;i<=60;++i){
		swap(f,g);
		memset(g,0,sizeof g);
		for(ri j=0;j<=n;++j){
			if(f[j][0])
				for(ri l=(z>>i)&1;l<=n&&j+l<=n<<1;l+=2){
					ri x=j+l>>1,y=(j+l)&1;
					(g[x][y>((k>>i)&1)]+=C[n][l]*f[j][0])%=mod;
				}
			if(f[j][1])
				for(ri l=(z>>i)&1;l<=n&&j+l<=n<<1;l+=2){
					ri x=j+l>>1,y=(j+l)&1;
					(g[x][y>=((k>>i)&1)]+=C[n][l]*f[j][1])%=mod;
				}
		}
	}
	return g[0][0]; 
}
ll l,r;
int main(){
	scanf("%d%lld%lld%lld",&n,&l,&r,&z);
	init(n);
	printf("%lld",(calc(r)+mod-calc(l-1))%mod);
	return 0;
}