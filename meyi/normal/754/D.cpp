#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int ans,ans2,b[maxn<<1],bl,cnt[maxn<<3],k,l[maxn],n,r[maxn],tag[maxn<<3];
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>v[maxn<<1];
inline void down(int p){
	cnt[p<<1]+=tag[p],cnt[p<<1|1]+=tag[p];
	tag[p<<1]+=tag[p],tag[p<<1|1]+=tag[p];
	tag[p]=0;
}
void add(int p,int l,int r,int k){
	if(r<=k){
		++cnt[p],++tag[p];
		return;
	}
	down(p);
	ri mid=l+r>>1;
	add(p<<1,l,mid,k);
	if(k>mid)add(p<<1|1,mid+1,r,k);
	cnt[p]=max(cnt[p<<1],cnt[p<<1|1]);
}
int query(int p,int l,int r){
	if(l==r)return cnt[p]>=k?l:0;
	down(p);
	ri mid=l+r>>1;
	return cnt[p<<1|1]>=k?query(p<<1|1,mid+1,r):query(p<<1,l,mid);
}
signed main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<=n;++i){
		scanf("%d%d",l+i,r+i);
		b[++bl]=l[i],b[++bl]=r[i];
	}
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	for(ri i=1;i<=n;++i)v[lower_bound(b+1,b+bl+1,l[i])-b].emplace_back(lower_bound(b+1,b+bl+1,r[i])-b,i);
	for(ri i=1;i<=bl;++i){
		for(const pii &j:v[i])add(1,1,bl,j.fi);
		ri pos=query(1,1,bl);
		if(pos>=i&&b[pos]-b[i]+1>ans)ans=b[pos]-b[i]+1,ans2=pos;
	}
	if(!ans){
		puts("0");
		for(ri i=1;i<=k;++i)printf("%d ",i);
	}
	else{
		printf("%d\n",ans);
		for(ri i=1;i<=bl;++i)
			for(const pii &j:v[i])
				if(j.fi>=ans2){
					printf("%d ",j.se);
					if(!--k)return 0;
				}
	}
	return 0;
}