#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],fir[maxn],m,n,pre[maxn],vis[maxn];
vector<int>to[maxn];
struct dsu{
	int fa[maxn];
	inline void init(int siz){for(ri i=1;i<=siz;++i)fa[i]=i;}
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline void merge(int x,int y){
		assert(x<=n&&y<=n);
		x=find(x),y=find(y);
		if(x!=y)fa[x]=y;
	}
}d;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i)scanf("%d",a+i),vis[a[i]]=i;
	d.init(n);
	for(ri i=2;i<=1000001;++i)
		if(!pre[i])
			for(ri j=i;j<=1000001;j+=i){
				pre[j]=i;
				if(vis[j]){
					if(!fir[i])fir[i]=vis[j];
					else d.merge(fir[i],vis[j]);
				}
			}
	for(ri i=2;i<=1000001;++i)
		if(vis[i-1]){
			ri j=i;
			vector<int>tmp={d.find(vis[i-1])};
			while(j>1){
				ri p=pre[j];
				if(fir[p])tmp.push_back(d.find(fir[p]));
				while(j%p==0)j/=p;
			}
			sort(tmp.begin(),tmp.end());
			tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
			for(j=0;j<tmp.size();++j)
				for(ri k=j+1;k<tmp.size();++k)
					to[tmp[j]].push_back(tmp[k]);
		}
	for(ri i=1;i<=n;++i)
		if(to[i].size()){
			sort(to[i].begin(),to[i].end());
			to[i].erase(unique(to[i].begin(),to[i].end()),to[i].end());
		}
	while(m--){
		ri x,y;
		scanf("%d%d",&x,&y);
		x=d.find(x),y=d.find(y);
		if(x==y)puts("0");
		else{
			if(x>y)swap(x,y);
			auto it=lower_bound(to[x].begin(),to[x].end(),y);
			if(it!=to[x].end()&&*it==y)puts("1");
			else puts("2");
		}
	}
	return 0;
}