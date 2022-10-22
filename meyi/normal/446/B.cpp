// CF446B
//  
#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e3+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn][maxn],cnt,k,m,n,p;
ll ans=LLONG_MIN,c[maxn*maxn],r[maxn*maxn];
priority_queue<ll>q;
int main(){
	scanf("%d%d%d%d",&n,&m,&k,&p);
	for(ri i=1;i<=n;++i)
		for(ri j=1;j<=m;++j)
			scanf("%d",&a[i][j]);
	for(ri i=1;i<=n;++i){
		ll sum=0;
		for(ri j=1;j<=m;++j)sum+=a[i][j];
		q.push(sum);
	}
	for(ri i=1;i<=k;++i){
		ll tmp=q.top();q.pop();
		r[i]=r[i-1]+tmp;
		q.push(tmp-1ll*p*m);
	}
	priority_queue<ll>().swap(q);
	for(ri j=1;j<=m;++j){
		ll sum=0;
		for(ri i=1;i<=n;++i)sum+=a[i][j];
		q.push(sum);
	}
	for(ri i=1;i<=k;++i){
		ll tmp=q.top();q.pop();
		c[i]=c[i-1]+tmp;
		q.push(tmp-1ll*p*n);
	}
	for(ri i=0;i<=k;++i)ckmax(ans,c[i]+r[k-i]-1ll*i*(k-i)*p);
	printf("%lld",ans);
	return 0;
}