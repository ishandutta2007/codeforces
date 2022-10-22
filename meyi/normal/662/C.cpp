#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1<<20|1,maxm=1e5+10,mod=998244353,inv2=(mod+1)>>1;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int all;
inline void XOR(int *f,int v){
	for(ri k=1,kk=2;kk<=all;k<<=1,kk<<=1)
		for(ri i=0;i<all;i+=kk)
			for(ri j=0;j<k;++j){
				ri x=(f[i|j]+f[i|j|k])%mod,y=(f[i|j]-f[i|j|k]+mod)%mod;
				f[i|j]=1ll*x*v%mod,f[i|j|k]=1ll*y*v%mod;
			}
}
int ans=INT_MAX,b[maxm],cnt[maxn],f[maxn],m,n,pop[maxn];
char s[maxm];
signed main(){
	scanf("%d%d",&n,&m);
	all=1<<n;
	for(ri i=0;i<n;++i){
		scanf("%s",s);
		for(ri j=0;j<m;++j)b[j]=(b[j]<<1)|(s[j]^48);
	}
	for(ri i=0;i<m;++i)++cnt[b[i]];
	for(ri i=0;i<all;++i){
		pop[i]=__builtin_popcount(i);
		ckmin(pop[i],n-pop[i]);
	}
	XOR(cnt,1),XOR(pop,1);
	for(ri i=0;i<all;++i)f[i]=1ll*cnt[i]*pop[i]%mod;
	XOR(f,inv2);
	for(ri i=0;i<all;++i)ckmin(ans,f[i]);
	printf("%d",ans);
	return 0;
}