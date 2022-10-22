#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3010;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
ll ans,w[maxn];
vector<int>a[maxn];
int m,n,v[maxn];
void solve(vector<ll>f,int l,int r){
	if(l==r){
		ckmax(ans,f[m]);
		ri cnt=0;
		ll sum=0;
		for(auto i:a[l]){
			++cnt;
			if(cnt>m)break;
			sum+=i;
			ckmax(ans,f[m-cnt]+sum);
		}
		return;
	}
	ri mid=l+r>>1;
	vector<ll>tmp=f;
	for(ri i=l;i<=mid;++i)
		for(ri j=m;j>=v[i];--j)
			ckmax(f[j],f[j-v[i]]+w[i]);
	solve(f,mid+1,r);
	f=tmp;
	for(ri i=mid+1;i<=r;++i)
		for(ri j=m;j>=v[i];--j)
			ckmax(f[j],f[j-v[i]]+w[i]);
	solve(f,l,mid);
}
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i){
		scanf("%d",v+i);
		a[i].resize(v[i]);
		for(auto &j:a[i])scanf("%d",&j),w[i]+=j;
	}
	solve(vector<ll>(m+1),1,n);
	printf("%lld",ans);
	return 0;
}