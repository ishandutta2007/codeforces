#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
ll a[MAXN],b[MAXN];
ll gcd(ll a,ll b){
	if(!b) return a;
	return gcd(b,a%b);
}
ll sum[MAXN<<2];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
void Build(int k,int l,int r){
	if(l==r){
		sum[k]=b[l];
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	sum[k]=gcd(sum[lc],sum[rc]);
	return ;
}
ll Query(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y) return sum[k];
	int mid=l+r>>1;
	ll res=0;
	if(x<=mid) res=gcd(Query(ls,x,y),res);
	if(mid<y) res=gcd(Query(rs,x,y),res);
	return res;
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%lld",a+i);
			b[i]=a[i]-a[i-1];
			if(b[i]<0) b[i]=-b[i];
		}
		Build(1,1,n);
		int ans=1;
		ll g=0;
		for(int i=2,w=1; i<=n; i++){
			g=gcd(b[i],g);
			while(g==1){
				w++;
				if(w<i) g=Query(1,1,n,w+1,i);
				else g=0;
			}
			ans=max(ans,i-w+1);
			//printf("%d w %d g %d\n",i,w,g);
		}
		printf("%d\n",ans);
	}
	return 0;
}