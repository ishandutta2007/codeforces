#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=5e5+10;
int lg,lg2[maxn],m,n,t_case;
ll a[maxn],st[21][maxn];
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
inline bool check(int l,int k){
	ri r=l+k-1;
	k=lg2[k];
	return gcd(st[k][l],st[k][r-(1<<k)+1])>1;
}
int main(){
	for(ri i=1;i<=200000;++i)lg2[i]=lg2[i-1]+((2<<lg2[i-1])==i);
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%lld",a+i);
		if(n==1){
			puts("1");
			continue;
		}
		for(ri i=1;i<=n;++i)st[0][i]=0;
		for(ri i=1;i<n;++i)st[0][i]=llabs(a[i+1]-a[i]);
		lg=lg2[n-1];
		for(ri i=1;i<=lg;++i)
			for(ri j=1;j<=n;++j)
				st[i][j]=0;
		for(ri i=1;i<=lg;++i)
			for(ri j=1;j+(1<<i)-1<n;++j)
				st[i][j]=gcd(st[i-1][j],st[i-1][j+(1<<(i-1))]);
		ri ans=0;
		for(ri i=1;i<n;++i){
			ri l=1,r=n-i,tmp=0;
			while(l<=r){
				ri mid=l+r>>1;
				if(check(i,mid))tmp=mid,l=mid+1;
				else r=mid-1;
			}
			ckmax(ans,tmp);
		}
		printf("%d\n",ans+1);
	}
	return 0;
}