#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int cnt[maxn],c1[maxn],c2[maxn],k,n,t_case;
inline void add(int k,int v1,int v2){
	for(;k<=n;k+=k&-k)c1[k]+=v1,c2[k]+=v2;
}
inline int query2(int k){
	ri ret=0;
	for(ri i=k;i;i^=i&-i)ret+=c2[i];
	for(ri i=k-1;i;i^=i&-i)ret-=c2[i];
	return ret;
}
inline int half(){
	ri now=0,sum=0,tot=0;
	for(ri i=16;~i;--i){
		ri nxt=now|(1<<i);
		if(nxt<=n&&sum+c1[nxt]<=k)now=nxt,sum+=c1[nxt],tot+=c2[nxt];
	}
	if(now<n)tot+=min(query2(now+1),(int)(k-sum)/(now+1));
	return tot;
}
signed main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d",&n,&k);
		map<int,int>b;
		clear(cnt,n);
		for(ri i=1,x;i<=n;++i)scanf("%d",&x),++(x<n?cnt[x]:b[x]);
		clear(c1,n),clear(c2,n);
		for(const auto &i:b)add(i.second,i.second,1);
		ri all=b.size();
		for(ri i=0;i<n;++i)
			if(cnt[i])
				add(cnt[i],cnt[i],1),++all;
		ri ans=INT_MAX,emp=0;
		for(ri emp=0,mex=0;mex<=n;++mex){
			ckmin(ans,mex+max((all-mex)-half(),mex?0:1)-mex);
			if(cnt[mex])add(cnt[mex],-cnt[mex],-1);
			else{
				++all;
				if(++emp>k)break;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}