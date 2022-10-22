#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int a[maxn],ans,b[maxn],cnt,d[maxn],id[maxn],m[maxn],mx,n,sub[maxn],t_case;
vector<int>p[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d",&n);
		ans=n;
		for(ri i=1;i<=n;++i){
			scanf("%d%d%d",a+i,b+i,m+i);
			d[i]=a[i]+b[i]-m[i];
		}
		sort(d+1,d+n+1);
		cnt=unique(d+1,d+n+1)-d-1;
		for(ri i=1;i<=cnt;++i)p[i].clear();
		for(ri i=1;i<=n;++i)p[lower_bound(d+1,d+cnt+1,a[i]+b[i]-m[i])-d].push_back(i);
		mx=0;
		for(ri i=1;i<=cnt;++i){
			typedef pair<int,int> pii;
			#define fi first
			#define se second
			set<pii>s;
			sort(p[i].begin(),p[i].end(),[&](const int &x,const int &y){return a[x]-m[x]<a[y]-m[y];});
			for(auto j:p[i]){
				while(s.size()&&s.begin()->fi<max(a[j]-m[j],0))sub[s.begin()->se]=s.begin()->fi,s.erase(s.begin());
				if(s.size()){
					--ans;
					id[j]=s.begin()->se;
					pii tmp={min(s.begin()->fi,a[j]-max(m[j]-b[j],0)),s.begin()->se};
					s.erase(s.begin());
					s.insert(tmp);
				}
				else id[j]=++mx,s.insert(pii{a[j]-max(m[j]-b[j],0),id[j]});
			}
			for(auto j:s)sub[j.se]=j.fi;
		}
		printf("%d\n",ans);
		for(ri i=1;i<=n;++i)printf("%d %d\n",a[i]-sub[id[i]],m[i]-(a[i]-sub[id[i]]));
	}
	return 0;
}