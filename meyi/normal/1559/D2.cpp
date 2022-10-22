#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y,siz[y]+=siz[x];
	}
}d1,d2;
int m1,m2,n;
stack<int>s1,s2;
signed main(){
	scanf("%d%d%d",&n,&m1,&m2);
	d1.init(n),d2.init(n);
	while(m1--){
		ri x,y;
		scanf("%d%d",&x,&y);
		d1.merge(x,y);
	}
	while(m2--){
		ri x,y;
		scanf("%d%d",&x,&y);
		d2.merge(x,y);
	}
	typedef pair<int,int> pii;
	#define fi first
	#define se second
	vector<pii>ans;
	for(ri i=2;i<=n;++i)
		if(d1.find(1)!=d1.find(i)&&d2.find(1)!=d2.find(i)){
			ans.emplace_back(1,i);
			d1.merge(1,i);
			d2.merge(1,i);
		}
	for(ri i=2;i<=n;++i){
		if(d1.find(1)!=d1.find(i))s1.push(i);
		if(d2.find(1)!=d2.find(i))s2.push(i);
	}
	while(s1.size()||s2.size()){
		while(s1.size()&&d1.find(1)==d1.find(s1.top())&&d2.find(1)==d2.find(s1.top()))s1.pop();
		if(!s1.size())break;
		while(s2.size()&&d1.find(1)==d1.find(s2.top())&&d2.find(1)==d2.find(s2.top()))s2.pop();
		if(!s2.size())break;
		ans.emplace_back(s1.top(),s2.top());
		d1.merge(s1.top(),s2.top());
		d2.merge(s1.top(),s2.top());
		s1.pop(),s2.pop();
	}
	printf("%u\n",ans.size());
	for(auto i:ans)printf("%d %d\n",i.fi,i.se);
	return 0;
}