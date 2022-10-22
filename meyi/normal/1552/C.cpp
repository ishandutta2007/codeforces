#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=210;
typedef pair<int,int> pii;
#define fi first
#define se second
int k,m,n,t_case;
bool vis[maxn];
vector<pii>a;
vector<int>b;
inline bool check(const pii &x,const pii &y){
	return x.fi<y.fi&&x.se>y.fi&&y.se>x.se;
}
inline int calc(const vector<pii> &v){
	ri ret=0;
	for(ri i=0;i<v.size();++i)
		for(ri j=i+1;j<v.size();++j)
			ret+=(check(v[i],v[j])||check(v[j],v[i]));
	return ret;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		memset(vis,0,sizeof vis);
		a.clear();
		for(ri i=1,x,y;i<=k;++i){
			scanf("%d%d",&x,&y);
			vis[x]=vis[y]=true;
			if(x>y)swap(x,y);
			a.emplace_back(x,y);
		}
		b.clear();
		for(ri i=1;i<=n*2;++i)
			if(!vis[i])
				b.push_back(i);
		for(ri i=0;i<n-k;++i){
			if(b[i]>b[i+n-k])swap(b[i],b[i+n-k]);
			a.emplace_back(b[i],b[i+n-k]);
		}
		printf("%d\n",calc(a));
	}
	return 0;
}