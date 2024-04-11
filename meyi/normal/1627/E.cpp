#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=1e5+10;
int a[maxn],b[maxn],c[maxn],d[maxn],h[maxn],k,m,n,t_case;
ll f[maxn],x[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
map<pii,ll>fr;
vector<int>p[maxn],pp[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&m,&k);
		for(ri i=1;i<=n;++i)vector<int>().swap(p[i]),vector<int>().swap(pp[i]),scanf("%lld",x+i);
		pp[1].push_back(1),pp[n].push_back(m);
		for(ri i=1;i<=k;++i){
			scanf("%d%d%d%d%d",a+i,b+i,c+i,d+i,h+i);
			p[a[i]].push_back(i);
		}
		clear(f,m,0x3f);
		f[1]=0;
		fr.clear();
		for(ri i=1;i<=n;++i){
			vector<int>tmp;
			for(ri j:p[i])tmp.push_back(b[j]);
			for(ri j:pp[i])tmp.push_back(j);
			if(tmp.size()){
				for(ri j:tmp)if(fr.count({i,j}))ckmin(f[j],fr[{i,j}]);
				sort(tmp.begin(),tmp.end());
				tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
				ri best=tmp.front();
				for(ri j:tmp){
					if(f[best]+(j-best)*x[i]<f[j])f[j]=f[best]+(j-best)*x[i];
					else best=j;
				}
				best=tmp.back();
				for(ri j:tmp|ranges::views::reverse){
					if(f[best]+(best-j)*x[i]<f[j])f[j]=f[best]+(best-j)*x[i];
					else best=j;
				}
				for(ri j:p[i])
					if(f[b[j]]!=f[0]){
						if(fr.count({c[j],d[j]}))ckmin(fr[{c[j],d[j]}],f[b[j]]-h[j]);
						else fr[{c[j],d[j]}]=f[b[j]]-h[j];
						pp[c[j]].push_back(d[j]);
					}
				if(i<n)for(ri j:tmp)f[j]=f[0];
			}
		}
		if(f[m]==f[0])puts("NO ESCAPE");
		else printf("%lld\n",f[m]);
	}
	return 0;
}