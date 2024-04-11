#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define DEBUG(k...) fprintf(stderr,k)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,t_case;
ll a[maxn],ans,b[maxn],pre[maxn],suf[maxn];;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%lld",a+i);
	for(ri i=1;i<=n;++i){
		scanf("%lld",b+i);
		ans+=a[i]*b[i];
	}
	for(ri i=1;i<=n;++i)pre[i]=pre[i-1]+a[i]*b[i];
	for(ri i=n;i;--i)suf[i]=suf[i+1]+a[i]*b[i];
	for(ri i=1;i<=n;++i){
		ri d=1;
		ll tmp=a[i]*b[i];
		while(i-d>0&&i+d<=n){
			tmp+=a[i-d]*b[i+d]+a[i+d]*b[i-d];
			ans=max(ans,pre[i-d-1]+tmp+suf[i+d+1]);
			++d;
		}
	}
	for(ri i=1;i<n;++i){
		ri d=1;
		ll tmp=a[i]*b[i+1]+a[i+1]*b[i];
		ans=max(ans,pre[i-1]+tmp+suf[i+1+1]);
		while(i-d>0&&i+1+d<=n){
			tmp+=a[i-d]*b[i+1+d]+a[i+1+d]*b[i-d];
			ans=max(ans,pre[i-d-1]+tmp+suf[i+1+d+1]);
			++d;
		}
	}
	printf("%lld",ans);
	return 0;
}