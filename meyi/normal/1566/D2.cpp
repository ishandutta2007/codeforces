#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxm=1e5+10,maxn=310;
#define lowbit(k) ((k)&(-k))
template<typename T>
struct BIT{
	T c[maxm];
	int mx_idx;
	inline void clear(){memset(c,0,sizeof(T)*(mx_idx+1));}
	inline void add(int k,T v){
		for(;k<=mx_idx;k+=lowbit(k))c[k]+=v;
	}
	inline T query(int k){
		T ret=0;
		for(;k;k^=lowbit(k))ret+=c[k];
		return ret;
	}
	inline T query(int l,int r){
		return query(r)-query(l-1);
	}
};
BIT<ll>t;
int a[maxn][maxn],ans[maxn][maxn],b[maxm],bl,m,n,t_case;
vector<int>v[maxm];
typedef pair<int,int> pii;
#define fi first
#define se second
inline bool cmp(pii x,pii y){
	if(x.fi!=y.fi)return x.fi>y.fi;
	return x.se<y.se;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&m);
		bl=0;
		for(ri i=1;i<=n;++i)
			for(ri j=1;j<=m;++j)
				scanf("%d",&a[i][j]),b[++bl]=a[i][j];
		sort(b+1,b+bl+1);
		bl=unique(b+1,b+bl+1)-b-1;
		t.mx_idx=n*m;
		for(ri i=1;i<=bl;++i)v[i].clear();
		for(ri i=n;i;--i)
			for(ri j=m;j;--j){
				a[i][j]=lower_bound(b+1,b+bl+1,a[i][j])-b;
				v[a[i][j]].push_back((i-1)*m+j);
			}
		ri x=1,y=1;
		for(ri i=1;i<=bl;++i){
			vector<pii>pos;
			for(ri j=0;j<v[i].size();++j){
				pos.emplace_back(x,y);
				++y;
				if(y>m)++x,y=1;
			}
			sort(pos.begin(),pos.end(),cmp);
			for(ri j=0;j<v[i].size();++j)ans[pos[j].fi][pos[j].se]=v[i][j];
		}
		ll sum=0;
		for(ri i=1;i<=n;++i){
			t.clear();
			for(ri j=1;j<=m;++j)sum+=t.query(ans[i][j]),t.add(ans[i][j],1);
		}
		printf("%lld\n",sum);
	}
	return 0;
}