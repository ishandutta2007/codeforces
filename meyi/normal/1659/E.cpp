#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
bool even[maxn];
struct dsu{
	int fa[maxn],siz[maxn];
	bool flag[maxn];
	inline void init(int k){for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
			return true;
		}
		return false;
	}
}d[59];
int m,n,q,x[maxn],y[maxn],z[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=0;i<59;++i)d[i].init(n);
	for(ri i=1;i<=m;++i){
		scanf("%d%d%d",x+i,y+i,z+i);
		for(ri j=0;j<30;++j)
			if(z[i]&(1<<j))
				d[j].merge(x[i],y[i]);
		if(z[i]&1){
			for(ri j=1;j<30;++j)
				if(z[i]&(1<<j))
					d[29+j].merge(x[i],y[i]);
		}
		else even[x[i]]=even[y[i]]=true;
	}
	for(ri i=1;i<=n;++i)
		if(even[i])
			for(ri j=0;j<59;++j)
				d[j].flag[d[j].find(i)]=true;
	scanf("%d",&q);
	while(q--){
		ri u,v;
		scanf("%d%d",&u,&v);
		for(ri i=0;i<30;++i)
			if(d[i].find(u)==d[i].find(v)){
				puts("0");
				goto skip;
			}
		for(ri i=30;i<59;++i)
			if(d[i].flag[d[i].find(u)]||d[i].find(u)==d[i].find(v)){
				puts("1");
				goto skip;
			}
		puts("2");
		skip:;
	}
}