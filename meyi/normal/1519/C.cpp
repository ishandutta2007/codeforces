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
int a[maxn],m,n,t_case;
vector<ll>sum[maxn];
inline bool cmp1(int x,int y){
	return x>y;
}
inline bool cmp2(vector<ll> x,vector<ll> y){
	return x.size()>y.size();
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		for(ri i=1;i<=n;++i)scanf("%d",a+i),sum[i].clear();
		for(ri i=1;i<=n;++i){
			ri x;
			scanf("%d",&x);
			sum[a[i]].pb(x);
		}
		for(ri i=1;i<=n;++i)
			if(SZ(sum[i])){
				sort(ALL(sum[i]),cmp1);
				for(ri j=1;j<SZ(sum[i]);++j)sum[i][j]+=sum[i][j-1];
			}
		sort(sum+1,sum+n+1,cmp2);
		for(ri i=1;i<=n;++i){
			ll ans=0;
			for(ri j=1;j<=n&&SZ(sum[j])>=i;++j)ans+=sum[j][(SZ(sum[j])/i)*i-1];
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}