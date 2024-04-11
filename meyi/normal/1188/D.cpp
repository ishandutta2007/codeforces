#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
ll a[maxn];
int cnt[maxn][2],f[59][maxn],id[maxn],n;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	for(ri i=1;i<=n;++i)a[i]=a[n]-a[i];
	memset(f,0x3f,sizeof f);
	f[0][0]=0;
	for(ri i=0;i<58;++i){
		ll bitmask=(1ll<<i)-1;
		sort(a+1,a+n+1,[&](const ll &x,const ll &y){return (x&bitmask)<(y&bitmask);});
		for(ri j=1;j<=n;++j){
			cnt[j][0]=cnt[j-1][0],cnt[j][1]=cnt[j-1][1];
			++cnt[j][(a[j]>>i)&1];
		}
		// f[i][j]  i  j 
		// cnt[k][0/1]  k  i  0/1  
		for(ri j=0;j<=n;++j){
			int cnt1=cnt[n-j][1]+cnt[n][0]-cnt[n-j][0],to=cnt[n][1]-cnt[n-j][1];
			ckmin(f[i+1][to],f[i][j]+cnt1);
			//  0
			//  n-j  j  1 
			//   j  1 
			cnt1=cnt[n-j][0]+cnt[n][1]-cnt[n-j][1],to=n-cnt[n-j][0];
			ckmin(f[i+1][to],f[i][j]+cnt1);
			//  1
			//  n-j   j  0 
			//  1  
		}
	}
	printf("%d",f[58][0]);
	return 0;
}