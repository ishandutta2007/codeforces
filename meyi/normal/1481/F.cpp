#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+1;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
bitset<maxn>b,lst;
int ans,cnt[maxn],m,n,siz[maxn],x;
vector<int>e[maxn],v1[maxn],v2[maxn];
void dfs(int p,int d){
	ckmax(ans,d);
	++siz[d];
	v1[d].push_back(p);
	for(ri i:e[p])dfs(i,d+1);
}
typedef pair<int,int> pii;
#define fi first
#define se second
pii pre[maxn];
char s[maxn];
void dfs(int k){
	if(!k)return;
	for(ri i=1;i<=pre[k].se;++i){
		for(ri j:v1[v2[pre[k].fi].back()])s[j]='a';
		v2[pre[k].fi].pop_back();
	}
	dfs(k-pre[k].fi*pre[k].se);
}
int main(){
	scanf("%d%d",&n,&x);
	for(ri i=2,f;i<=n;++i)scanf("%d",&f),e[f].push_back(i);
	dfs(1,1);
	for(ri i=1;i<=ans;++i){
		++cnt[siz[i]];
		v2[siz[i]].push_back(i);
	}
	b[0]=lst[0]=1;
	for(ri i=1;i<=n;++i)
		for(ri j=1;cnt[i];j=min(j<<1,cnt[i])){
			b|=b<<i*j;
			bitset<maxn>tmp=b^lst;
			for(ri k=tmp._Find_first();k<maxn;k=tmp._Find_next(k))lst[k]=1,pre[k]={i,j};
			cnt[i]-=j;
		}
	if(b[x]){
		printf("%d\n",ans);
		dfs(x);
		for(ri i=1;i<=n;++i)
			if(!s[i])
				s[i]='b';
		printf("%s",s+1);
	}
	else{
		printf("%d\n",ans+1);
		ri cnt[2]={x,n-x};
		for(ri i=1;i<=ans;++i){
			sort(v1[i].begin(),v1[i].end(),[&](int x,int y){return e[x].size()>e[y].size();});
			bool f=cnt[0]<cnt[1];
			for(ri j:v1[i]){
				if(!cnt[f])f^=1;
				s[j]='a'+f,--cnt[f];
			}
		}
		printf("%s",s+1);
	}
	return 0;
}