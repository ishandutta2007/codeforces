#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
struct dsu{
	int fa[maxn];
	vector<int>v[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,v[i]={i};}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(v[x].size()>v[y].size())swap(x,y);
			fa[x]=y;
			for(auto i:v[x])v[y].push_back(i);
		}
	}
}d;
int a[maxn],m,n,t_case;
signed main(){
	scanf("%d",&n);
	d.init(n);
	for(ri i=1,x,y;i<n;++i){
		scanf("%d%d",&x,&y);
		d.merge(x,y);
	}
	ri tmp=d.find(1);
	for(auto i:d.v[tmp])printf("%d ",i);
	return 0;
}