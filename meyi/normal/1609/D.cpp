#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=1e3+10;
int ans,cnt;
multiset<int,greater<int>>s;
struct dsu{
	int fa[maxn],siz[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,s.insert(1),siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			s.erase(s.find(siz[x])),s.erase(s.find(siz[y]));
			fa[x]=y,siz[y]+=siz[x];
			ckmax(ans,siz[y]-1);
			s.insert(siz[y]);
			return true;
		}
		return false;
	}
}d;
int a[maxn],m,n,t_case;
int main(){
	scanf("%d%d",&n,&m);
	d.init(n);
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		if(!d.merge(x,y))++cnt;
		auto it=++s.begin();
		ri sum=0;
		for(ri i=1;i<=cnt;++i)
			if(it!=s.end()){
				sum+=*it;
				++it;
			}
			else break;
		printf("%d\n",ans+sum);
	}
	return 0;
}