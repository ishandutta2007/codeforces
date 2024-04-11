#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],k,m,n,op[maxn],pos[maxn],val[maxn];
vector<int>ans;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<pll,int> ppi;
#define fi first
#define se second
pii q1[maxn];
vector<pii>q2[maxn];
vector<ppi>q3;
signed main(){
	scanf("%d%d%d",&n,&m,&k);
	for(ri i=1;i<=n;++i)scanf("%d",a+i);
	for(ri i=1;i<=m;++i){
		scanf("%d%d%d",op+i,pos+i,val+i);
		if(op[i]==1)ckmax(q1[pos[i]],pii{val[i],i});
		else if(op[i]==2)q2[pos[i]].emplace_back(val[i],i);
		else q3.emplace_back(pll{val[i],1},i);
	}
	for(ri i=1;i<=n;++i){
		if(q1[i].fi>a[i])q2[i].emplace_back(q1[i].fi-a[i],q1[i].se);
		sort(q2[i].begin(),q2[i].end(),greater<pii>());
		ll sum=a[i];
		for(auto j:q2[i])q3.emplace_back(pll{sum+j.fi,sum},j.se),sum+=j.fi;
	}
	sort(q3.begin(),q3.end(),[&](const ppi &x,const ppi &y){return (double)x.fi.fi/x.fi.se>(double)y.fi.fi/y.fi.se;});
	for(ri i=min(k,(int)q3.size())-1;i>=0;--i)ans.push_back(q3[i].se);
	sort(ans.begin(),ans.end(),[&](const int &x,const int &y){return op[x]<op[y];});
	printf("%d\n",ans.size());
	for(auto i:ans)printf("%d ",i);
	return 0;
}